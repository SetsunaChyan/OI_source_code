#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;
int tot,n,m,seg[MAXN<<2],lazy[MAXN<<2],r[MAXN],l[MAXN],head[MAXN],deg[MAXN],cnt;
struct edge
{
    int to,nxt;
}e[MAXN<<1];

inline void clear()
{
    cnt=tot=0;
    memset(deg,0,sizeof(deg));
    memset(lazy,-1,sizeof(lazy));
    memset(head,-1,sizeof(head));
}

inline void add_edge(int x,int y)
{
    e[tot].nxt=head[x];
    e[tot].to=y;
    head[x]=tot;
    tot++;
}

void dfs(int now)
{
    cnt++;
    l[now]=cnt;
    for(int i=head[now];~i;i=e[i].nxt)
        dfs(e[i].to);
    r[now]=cnt;
}

inline void pushdown(int rt)
{
    if(lazy[rt]==-1) return;
    seg[rt<<1]=seg[rt<<1|1]=lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt]=-1;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=-1;
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]=seg[rt]=x;
        return;
    }
    pushdown(rt);
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,x);
}

int query(int rt,int l,int r,int x)
{
    if(l==r) return seg[rt];
    pushdown(rt);
    int m=l+r>>1;
    if(x<=m) return query(rt<<1,l,m,x);
    else return query(rt<<1|1,m+1,r,x);
}

void solve(int cs)
{
    clear();
    scanf("%d",&n);
    build(1,1,n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        deg[x]++;
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        if(deg[i]==0)
        {
            dfs(i);
            break;
        }

    scanf("%d ",&m);
    printf("Case #%d:\n",cs);
    while(m--)
    {
        char op[20];
        int x,y;
        gets(op);
        if(op[0]=='C') 
        {
            sscanf(op,"%*c%d",&x);
            printf("%d\n",query(1,1,n,l[x]));
        }
        else if(op[0]=='T')
        {
            sscanf(op,"%*c%d%d",&x,&y);
            modify(1,1,n,l[x],r[x],y);
        }
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++) solve(i); 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN=30005;
int n,q,sum[MAXN<<2],maxn[MAXN<<2],top[MAXN],dep[MAXN],fa[MAXN],son[MAXN],siz[MAXN],id[MAXN],head[MAXN],tmp[MAXN],a[MAXN],tot=0,cnt=0;
char op[15];
struct edge
{
    int to,nxt;
}e[MAXN<<1];

inline void add_edge(int x,int y)
{
    e[tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot++;
}

void dfs1(int now,int u)
{
    dep[now]=dep[u]+1;
    son[now]=0;
    siz[now]=1;
    fa[now]=u;
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=u)
        {
            dfs1(e[i].to,now);
            siz[now]+=siz[e[i].to];
            if(siz[e[i].to]>siz[son[now]]) son[now]=e[i].to;
        }
}

void dfs2(int now,int u)
{
    id[now]=++cnt;
    top[now]=u;
    if(son[now]) dfs2(son[now],u);
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=son[now]&&e[i].to!=fa[now])
            dfs2(e[i].to,e[i].to);
}

inline void pushup(int rt)
{
    maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        maxn[rt]=sum[rt]=a[l];
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        maxn[rt]=sum[rt]=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt);
}

int query1(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return maxn[rt];
    int m=l+r>>1,ret=0xc0c0c0c0;
    if(L<=m) ret=max(ret,query1(rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query1(rt<<1|1,m+1,r,L,R));
    return ret;
}

int query2(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return sum[rt];
    int m=l+r>>1,ret=0;
    if(L<=m) ret+=query2(rt<<1,l,m,L,R);
    if(m<R) ret+=query2(rt<<1|1,m+1,r,L,R);
    return ret;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&tmp[i]);
    dep[1]=0,siz[0]=0;
    dfs1(1,1);dfs2(1,1);
    for(int i=1;i<=n;i++)
        a[id[i]]=tmp[i];
    build(1,1,n);
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%s%d%d",op,&x,&y);
        if(op[1]=='H') modify(1,1,n,id[x],y);
        else if(op[1]=='M')
        {
            int ans=0xc0c0c0c0;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                ans=max(ans,query1(1,1,n,id[top[x]],id[x]));
                x=fa[top[x]];
            }
            if(dep[x]<dep[y]) swap(x,y);
            ans=max(ans,query1(1,1,n,id[y],id[x]));
            printf("%d\n",ans);
        }
        else
        {
            int ans=0;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                ans+=query2(1,1,n,id[top[x]],id[x]);
                x=fa[top[x]];
            }
            if(dep[x]<dep[y]) swap(x,y);
            ans+=query2(1,1,n,id[y],id[x]);
            printf("%d\n",ans);
        }
    }
    return 0;
}

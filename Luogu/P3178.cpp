#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100005;
ll tmp[MAXN],a[MAXN],seg[MAXN<<2],add[MAXN<<2];
int n,q,id[MAXN],dep[MAXN],son[MAXN],fa[MAXN],head[MAXN],siz[MAXN],top[MAXN],tot=0,cnt=0;
struct edge
{
    int to,nxt;
}e[MAXN<<2];

inline void add_edge(int x,int y)
{
    e[tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot++;
}

void dfs1(int now,int u)
{
    dep[now]=dep[u]+1;
    fa[now]=u;
    son[now]=0;
    siz[now]=1;
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
        if(e[i].to!=fa[now]&&e[i].to!=son[now])
            dfs2(e[i].to,e[i].to);
}

inline void pushup(int rt)
{
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

inline void pushdown(int rt,ll lnum,ll rnum)
{
    if(!add[rt]) return;
    seg[rt<<1]+=add[rt]*lnum;
    seg[rt<<1|1]+=add[rt]*rnum;
    add[rt<<1]+=add[rt];
    add[rt<<1|1]+=add[rt];
    add[rt]=0;
}

void build(int rt,int l,int r)
{
    add[rt]=0;
    if(l==r)
    {
        seg[rt]=a[l];
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,ll x)
{
    if(L<=l&&r<=R)
    {
        add[rt]+=x;
        seg[rt]+=x*(r-l+1);
        return;
    }
    int m=l+r>>1;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1;ll ret=0;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) ret+=query(rt<<1,l,m,L,R);
    if(m<R) ret+=query(rt<<1|1,m+1,r,L,R);
    pushup(rt);
    return ret;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&tmp[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dep[1]=0,siz[0]=0;
    dfs1(1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++)
        a[id[i]]=tmp[i];
    build(1,1,n);
    while(q--)
    {
        int op,x,y;ll z;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%lld",&x,&z);
            modify(1,1,n,id[x],id[x],z);
        }
        else if(op==2)
        {
            scanf("%d%lld",&x,&z);
            modify(1,1,n,id[x],id[x]+siz[x]-1,z);
        }
        else
        {
            scanf("%d",&x);
            ll ans=0;
            y=1;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                ans+=query(1,1,n,id[top[x]],id[x]);
                x=fa[top[x]];
            }
            if(dep[x]<dep[y]) swap(x,y);
            ans+=query(1,1,n,id[y],id[x]);
            printf("%lld\n",ans);
        }
    }

    return 0;
}

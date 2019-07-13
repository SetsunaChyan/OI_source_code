#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;
int n,q,tot=0,cnt=0,head[MAXN],lazy[MAXN<<2],seg[MAXN<<2],top[MAXN],son[MAXN],fa[MAXN],siz[MAXN],dep[MAXN],id[MAXN];
struct edge
{
    int to,nxt;
}e[MAXN<<1];

void add_edge(int x,int y)
{
    e[tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot++;
}

void dfs1(int now,int u)
{
    dep[now]=dep[u]+1;
    son[now]=0;
    fa[now]=u;
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
    top[now]=u;
    id[now]=++cnt;
    if(son[now]) dfs2(son[now],u);
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=fa[now]&&e[i].to!=son[now])
            dfs2(e[i].to,e[i].to);
}

inline void pushdown(int rt)
{
    if(lazy[rt]==-1) return;
    seg[rt<<1]=seg[rt<<1|1]=lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt]=-1;
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        seg[rt]=x;
        lazy[rt]=x;
        return;
    }
    int m=l+r>>1;
    pushdown(rt);
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,x);
}

int query(int rt,int l,int r,int x)
{
    if(l==r) return seg[rt];
    int m=l+r>>1;
    pushdown(rt);
    if(x<=m) return query(rt<<1,l,m,x);
    else return query(rt<<1|1,m+1,r,x);
}

int main()
{
    memset(head,-1,sizeof(head));
    memset(seg,0,sizeof(seg));
    memset(lazy,-1,sizeof(lazy));
    dep[1]=0,siz[0]=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(1,1);dfs2(1,1);
    scanf("%d",&q);
    while(q--)
    {
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1) modify(1,1,n,id[x],id[x]+siz[x]-1,1);
        else if(op==2)
        {
            int y=1;
            while(top[x]!=top[y])
            {
                if(dep[x]<dep[y]) swap(x,y);
                modify(1,1,n,id[top[x]],id[x],0);
                x=fa[top[x]];
            }
            if(dep[x]<dep[y]) swap(x,y);
            modify(1,1,n,id[y],id[x],0);
        }
        else printf("%d\n",query(1,1,n,id[x]));
    }
    return 0;
}

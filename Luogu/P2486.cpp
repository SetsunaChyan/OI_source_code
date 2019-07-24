#include <bits/stdc++.h>
using namespace std;

const int MAXN=10005;
int n,q,dep[MAXN],top[MAXN],son[MAXN],siz[MAXN],fa[MAXN],id[MAXN],head[MAXN],a[MAXN],tmp[MAXN],tot=0,cnt=1;
char op[10];
struct node
{
    int col,cor,cnt,tag;
}seg[MAXN<<2];
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
    fa[now]=u;
    siz[now]=1;
    son[now]=0;
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=u)
        {
            dfs1(e[i].to,now);
            siz[now]+=siz[e[i].to];
            if(siz[son[now]]<siz[e[i].to]) son[now]=e[i].to;
        }
}

void dfs2(int now,int u)
{
    top[now]=u;
    id[now]=cnt++;
    if(son[now]) dfs2(son[now],u);
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=fa[now]&&e[i].to!=son[now])
            dfs2(e[i].to,e[i].to);
}

inline void pushdown(int rt)
{
    if(!seg[rt].tag) return;
    int &x=seg[rt].tag;
    seg[rt<<1].col=seg[rt<<1|1].col=seg[rt<<1].cor=seg[rt<<1|1].cor=x;
    seg[rt<<1].tag=seg[rt<<1|1].tag=x;
    seg[rt<<1].cnt=seg[rt<<1|1].cnt=1;
    x=0;
}

inline void pushup(int rt)
{
    seg[rt].col=seg[rt<<1].col;
    seg[rt].cor=seg[rt<<1|1].cor;
    seg[rt].cnt=seg[rt<<1].cnt+seg[rt<<1|1].cnt;
    if(seg[rt<<1].cor==seg[rt<<1|1].col)
        seg[rt].cnt--;
}

void build(int rt,int l,int r)
{
    seg[rt].tag=0;
    if(l==r)
    {
        seg[rt].col=seg[rt].cor=a[l];
        seg[rt].cnt=1;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        seg[rt].col=seg[rt].cor=x;
        seg[rt].cnt=1;
        seg[rt].tag=c;
        return;
    }
    pushdown(rt);
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]),tmp[i]=a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dep[1]=0,siz[now]=0;
    dfs1(1,1);
    dfs2(1,1);
    for(int i=0;i<n;i++) a[id[i]]=tmp[i];
    build(1,1,n);
    while(q--)
    {
        int x,y,z;
        scanf("%s%d%d",op,&x,&y);
        if(op[0]=='Q')
        {
            scanf("%d",&z);
            while(top[x]!=top[y])
            {
                if(dep[x]<dep[y]) swap(x,y);

            }
        }
        else
        {


        }
    }
    return 0;
}

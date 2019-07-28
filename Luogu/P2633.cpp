#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int n,m,root[MAXN],tot,a[MAXN],tmp[MAXN],org[MAXN],X[2],Y[2],lastans,u,v,x,y,k;
int etot,cnt,head[MAXN],dep[MAXN],fa[MAXN],son[MAXN],siz[MAXN],top[MAXN];
struct node
{
    int lc,rc,val;
}seg[MAXN*30];
struct edge
{
    int to,nxt;
}e[MAXN<<1];

void add_edge(int x,int y)
{
    e[etot].to=y,e[etot].nxt=head[x],head[x]=etot++;
}

int build(int l,int r)
{
    int p=tot++;
    if(l==r)
    {
        seg[p].val=0;
        return p;
    }
    int m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    seg[p].val=seg[seg[p].lc].val+seg[seg[p].rc].val;
    return p;
}

int modify(int rt,int l,int r,int x)
{
    int p=tot++;
    seg[p]=seg[rt];
    if(l==r)
    {
        seg[p].val++;
        return p;
    }
    int m=l+r>>1;
    if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x);
    else seg[p].rc=modify(seg[rt].rc,m+1,r,x);
    seg[p].val=seg[seg[p].lc].val+seg[seg[p].rc].val;
    return p;
}

int query(int l,int r,int k)
{
    if(l==r) return l;
    int sum=0,m=l+r>>1;
    sum-=seg[seg[X[0]].lc].val+seg[seg[X[1]].lc].val;
    sum+=seg[seg[Y[0]].lc].val+seg[seg[Y[1]].lc].val;
    if(sum>=k)
    {
        X[0]=seg[X[0]].lc,X[1]=seg[X[1]].lc;
        Y[0]=seg[Y[0]].lc,Y[1]=seg[Y[1]].lc;
        return query(l,m,k);
    }
    else
    {
        X[0]=seg[X[0]].rc,X[1]=seg[X[1]].rc;
        Y[0]=seg[Y[0]].rc,Y[1]=seg[Y[1]].rc;
        return query(m+1,r,k-sum);
    }
}

void dfs1(int now,int u)
{
    fa[now]=u;
    dep[now]=dep[u]+1;
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
    top[now]=u;
    root[now]=modify(root[fa[now]],1,n,a[now]);
    if(son[now]) dfs2(son[now],u);
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=fa[now]&&e[i].to!=son[now])
            dfs2(e[i].to,e[i].to);
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),tmp[i]=a[i];
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=n;i++)
    {
        k=lower_bound(tmp+1,tmp+1+n,a[i])-tmp;
        org[k]=a[i];a[i]=k;
    }
    dep[0]=0,siz[0]=0;
    dfs1(1,0);
    root[0]=build(1,n);
    dfs2(1,0);
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&k);
        x^=lastans;
        Y[0]=root[x];
        Y[1]=root[y];
        while(top[x]!=top[y])
        {
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y]) swap(x,y);
        X[0]=root[y];
        X[1]=root[fa[y]];
        printf("%d\n",lastans=org[query(1,n,k)]);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int fa[MAXN][20],dep[MAXN],head[MAXN],root[MAXN],etot,tot,n,m,q,a[MAXN],tmp[MAXN],org[MAXN],X[2],Y[2],lastans,vis[MAXN],viscnt,siz[MAXN],lg[MAXN];
struct node
{
    int lc,rc,cnt;
}seg[MAXN*300];
struct edge
{
    int to,nxt;
}e[MAXN<<1];

int add_edge(int x,int y)
{
    e[etot].to=y,e[etot].nxt=head[x],head[x]=etot++;
}

int build(int l,int r)
{
    int p=tot++;
    if(l==r)
    {
        seg[p].cnt=0;
        return p;
    }
    int m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
    return p;
}

int modify(int rt,int l,int r,int x)
{
    int p=tot++;
    seg[p]=seg[rt];
    if(l==r)
    {
        seg[p].cnt++;
        return p;
    }
    int m=l+r>>1;
    if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x);
    else seg[p].rc=modify(seg[rt].rc,m+1,r,x);
    seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
    return p;
}

int query(int l,int r,int k)
{
    if(l==r) return l;
    int sum=0,m=l+r>>1;
    sum-=seg[seg[X[0]].lc].cnt+seg[seg[X[1]].lc].cnt;
    sum+=seg[seg[Y[0]].lc].cnt+seg[seg[Y[1]].lc].cnt;
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

int dfs(int now,int u,int v)
{
    siz[v]++;
    vis[now]=v;
    dep[now]=dep[u]+1;
    fa[now][0]=u;
    root[now]=modify(root[u],1,n,a[now]);
    for(int i=1;i<20;i++)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=u) dfs(e[i].to,now,v);
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]!=dep[y])
        x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return x;
    for(int i=lg[dep[x]]-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

void solve()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),tmp[i]=a[i];
    sort(tmp+1,tmp+1+n);
    for(int i=1;i<=n;i++)
    {
        int k=lower_bound(tmp+1,tmp+1+n,a[i])-tmp;
        org[k]=a[i],a[i]=k;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    root[0]=build(1,n);
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            viscnt++;
            dfs(i,0,viscnt);
        }
    while(q--)
    {
        char op[3];
        int x,y,k;
        scanf("%s",op);
        if(op[0]=='Q')
        {
            scanf("%d%d%d",&x,&y,&k);
            x^=lastans,y^=lastans,k^=lastans;
            int z=lca(x,y);
            Y[0]=root[x],Y[1]=root[y];
            X[0]=root[z],X[1]=root[fa[z][0]];
            printf("%d\n",lastans=org[query(1,n,k)]);
        }
        else
        {
            scanf("%d%d",&x,&y);
            x^=lastans,y^=lastans;
            add_edge(x,y);
            add_edge(y,x);
            if(siz[vis[y]]<siz[vis[x]]) swap(x,y);
            dfs(x,y,vis[y]);
        }
    }
}

int main()
{
    lg[0]=0;
    for(int i=1;i<=100000;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    scanf("%*d");
    solve();
    return 0;
}

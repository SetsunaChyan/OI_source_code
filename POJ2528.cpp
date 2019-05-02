#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=20005;
int n,seg[MAXN<<2],lazy[MAXN<<2],l[10005],r[10005],vis[10005],tot;
pair<int,int> e[20005];

void dis()
{
    int k=1;
    sort(e,e+2*n);
    for(int i=0;i<2*n;i++)
    {
        if(i&&e[i].first!=e[i-1].first) k++;
        if(e[i].second&1) r[e[i].second>>1]=k; else l[e[i].second>>1]=k;
    }
    tot=k;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void pushdown(int rt)
{
    if(!lazy[rt]) return;
    seg[rt<<1]=lazy[rt<<1]=lazy[rt];
    seg[rt<<1|1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt]=0;
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        seg[rt]=lazy[rt]=x;
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,x);
}

int query(int rt,int l,int r,int x)
{
    if(l==r) return seg[rt];
    pushdown(rt);
    int m=(l+r)>>1;
    if(x<=m) return query(rt<<1,l,m,x);
    else return query(rt<<1|1,m+1,r,x);
}

void solve()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    memset(lazy,0,sizeof(lazy));
    vis[0]=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[2*i]=make_pair(x,2*i);
        e[2*i+1]=make_pair(y,2*i+1);
    }
    dis();
    build(1,1,tot);
    for(int i=0;i<n;i++)
        modify(1,1,tot,l[i],r[i],i+1);
    for(int i=1;i<=tot;i++)
    {
        int k=query(1,1,tot,i);
        if(!vis[k]) ans++,vis[k]=1;
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();

    return 0;
}
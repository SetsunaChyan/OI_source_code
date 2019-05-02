#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int seg[MAXN<<2],a[MAXN],n,m;

void pushup(int rt)
{
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        seg[rt]=y;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt);
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=(l+r)>>1,ret=0;
    if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
    if(R>m) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
    return ret;
}

void solve()
{
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=0;i<m;i++)
    {
        char c;
        int x,y;
        scanf(" %c%d%d",&c,&x,&y);
        if(c=='U') modify(1,1,n,x,y);
        else printf("%d\n",query(1,1,n,x,y));
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
        solve();
    return 0;
}
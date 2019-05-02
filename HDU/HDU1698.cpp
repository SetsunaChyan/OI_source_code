#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int seg[MAXN<<2],lazy[MAXN<<2],x,y,z,n,m;

void pushup(int rt)
{
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

void pushdown(int rt,int sl,int sr)
{
    if(!lazy[rt]) return;
    seg[rt<<1]=sl*lazy[rt];
    seg[rt<<1|1]=sr*lazy[rt];
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt]=0;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]=x;
        seg[rt]=(r-l+1)*x;
        return;
    }
    int m=(l+r)>>1;
    pushdown(rt,(m-l)+1,r-m);
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt);
}

void solve(int cs)
{
    memset(lazy,0,sizeof(lazy));
    scanf("%d%d",&n,&m);
    build(1,1,n);
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&z);
        modify(1,1,n,x,y,z);
    }
    printf("Case %d: The total value of the hook is %d.\n",cs,seg[1]);
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++) solve(i);
    return 0;
}
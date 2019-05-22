#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int pre1[MAXN<<2],suf2[MAXN<<2],pre2[MAXN<<2],suf1[MAXN<<2],con1[MAXN<<2],con2[MAXN<<2],lazy1[MAXN<<2],lazy2[MAXN<<2];
char s[10];

inline void pushdown(int rt)
{

}

inline void pushup(int rt)
{

}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        pre1[rt]=pre2[rt]=suf1[rt]=suf2[rt]=con1[rt]=1;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(r>m) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {

    }
    int m=l+r>>1;
    pushdown(rt);
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,x);
}

void solve(int cs)
{
    memset(lazy1,-1,sizeof(lazy1));
    memset(lazy2,-1,sizeof(lazy2));
    scanf("%d%d",&n,&m);
    build(1,1,n);
    printf("Case %d:\n",cs);
    while(m--)
    {

    }
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++)
        solve(i);
    return 0;
}
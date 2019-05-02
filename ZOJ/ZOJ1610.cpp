#include <bits/stdc++.h>
using namespace std;

const int MAXN=8005;
int seg[MAXN<<2],lazy[MAXN<<2],a[MAXN],n,ans[MAXN];

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=-1;
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void pushdown(int rt)
{
    if(lazy[rt]==-1) return;
    seg[rt<<1]=seg[rt<<1|1]=lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt]=-1;
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
    memset(lazy,-1,sizeof(lazy));
    memset(ans,0,sizeof(ans));
    build(1,1,8000);
    while(n--)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        modify(1,1,8000,x+1,y,c);
    }
    for(int i=1;i<=8000;i++)
        a[i]=query(1,1,8000,i);
    for(int i=1;i<=8000;i++)
        if(i==1||a[i]!=a[i-1])
            if(~a[i]) ans[a[i]]++;
    for(int i=0;i<=8000;i++)
        if(ans[i]) printf("%d %d\n",i,ans[i]);
    printf("\n");
}

int main()
{
    while(~scanf("%d",&n)) solve();
    return 0;
}
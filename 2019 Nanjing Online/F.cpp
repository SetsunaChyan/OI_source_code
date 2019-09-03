#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int seg[MAXN<<2],seg2[MAXN<<2],n,k,a[MAXN],pos[MAXN];

void build(int rt,int l,int r)
{
    seg[rt]=0;
    if(l==r) return;
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void modify(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        seg[rt]=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1,ret=0;
    if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
    return ret;
}

void build2(int rt,int l,int r)
{
    seg2[rt]=a[l];
    if(l==r)
    {
        seg2[rt]=a[l];
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    if()
}

void modify2(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        seg[rt]=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

int query2(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1,ret=0;
    if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
    return ret;
}


void solve()
{
    scanf("%d%d",&n,&k);
    build(1,1,n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),pos[a[i]]=i;
    for(int i=1;i<=n;i++)
    {
        int l=max(1,pos[i]-k);
        int r=min(n,pos[i]+k);
        int k=query(1,1,n,l,r);
        modify(1,1,n,pos[i],k+1);
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",query(1,1,n,pos[i],pos[i])," \n"[i==n]);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

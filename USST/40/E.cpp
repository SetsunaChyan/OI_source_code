#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=200005;
int n,m;
ll seg[maxn<<2],cnt[maxn<<2],a[maxn];

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void pushup(int rt)
{
    seg[rt]=gcd(seg[rt<<1],seg[rt<<1|1]);
    cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=a[l];
        if(a[l]==1) cnt[l]=1; else cnt[l]=0;
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R)
{
    if(l==r)
    {
        seg[rt]=sqrt(seg[rt]);
        cnt[rt]=(seg[rt]==1);
        return;
    }
    if(cnt[rt]==r-l+1) return;
    int m=(l+r)>>1;
    if(L<=m) modify(rt<<1,l,m,L,R);
    if(m<R) modify(rt<<1|1,m+1,r,L,R);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
        return seg[rt];
    int m=(l+r)>>1;
    ll ret=0;
    if(L<=m) ret=gcd(query(rt<<1,l,m,L,R),ret);
    if(m<R) ret=gcd(query(rt<<1|1,m+1,r,L,R),ret);
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(!op) modify(1,1,n,l,r);
        else printf("%lld\n",query(1,1,n,l,r));
    }
    return 0;
}
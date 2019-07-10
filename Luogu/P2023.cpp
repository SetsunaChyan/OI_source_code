#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int MAXN=100005;
int q,n;
ll a[MAXN],seg[MAXN<<2],add[MAXN<<2],mul[MAXN<<2],mod;

inline void pushup(int rt)
{
    seg[rt]=(seg[rt<<1]+seg[rt<<1|1])%mod;
}

inline void pushdown(int rt,ll lnum,ll rnum)
{
    add[rt<<1]=add[rt<<1]*mul[rt]%mod,add[rt<<1|1]=add[rt<<1|1]*mul[rt]%mod;
    mul[rt<<1]=mul[rt<<1]*mul[rt]%mod,mul[rt<<1|1]=mul[rt<<1|1]*mul[rt]%mod;
    seg[rt<<1]=seg[rt<<1]*mul[rt]%mod,seg[rt<<1|1]=seg[rt<<1|1]*mul[rt]%mod;
    mul[rt]=1;
    add[rt<<1]=(add[rt<<1]+add[rt])%mod,add[rt<<1|1]=(add[rt<<1|1]+add[rt])%mod;
    seg[rt<<1]=(seg[rt<<1]+add[rt]*lnum%mod)%mod,seg[rt<<1|1]=(seg[rt<<1|1]+add[rt]*rnum%mod)%mod;
    add[rt]=0;
}

void build(int rt,int l,int r)
{
    add[rt]=0,mul[rt]=1;
    if(l==r)
    {
        seg[rt]=a[l];
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,int op,ll y)
{
    if(L<=l&&r<=R)
    {
        if(op==1) seg[rt]=seg[rt]*y%mod,mul[rt]=mul[rt]*y%mod,add[rt]=add[rt]*y%mod;
        else seg[rt]=(seg[rt]+y*(r-l+1)%mod)%mod,add[rt]=(add[rt]+y)%mod;
        return;
    }
    int m=l+r>>1;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) modify(rt<<1,l,m,L,R,op,y);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,op,y);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    ll ret=0;
    int m=l+r>>1;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) ret=(ret+query(rt<<1,l,m,L,R))%mod;
    if(m<R) ret=(ret+query(rt<<1|1,m+1,r,L,R))%mod;
    pushup(rt);
    return ret;
}

int main()
{
    scanf("%d%llu",&n,&mod);
    for(int i=1;i<=n;i++)
        scanf("%llu",&a[i]);
    build(1,1,n);
    scanf("%d",&q);
    while(q--)
    {
        int op,l,r;
        ll c;
        scanf("%d%d%d",&op,&l,&r);
        if(op==3)
        {
            printf("%llu\n",query(1,1,n,l,r));
            continue;
        }
        scanf("%llu",&c);
        modify(1,1,n,l,r,op,c);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100005;
ll seg[MAXN<<2],a[MAXN];
int cnt[MAXN<<2],n,m;

inline void pushup(int rt)
{
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
    cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=a[l],cnt[rt]=(a[l]==1);
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R)
{
    if(l==r)
    {
        seg[rt]=sqrt(seg[rt]),cnt[rt]=(seg[rt]==1);
        return;
    }
    if(cnt[rt]==r-l+1) return;
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R);
    if(R>m) modify(rt<<1|1,m+1,r,L,R);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1;
    ll ret=0;
    if(L<=m) ret+=query(rt<<1,l,m,L,R);
    if(R>m) ret+=query(rt<<1|1,m+1,r,L,R);
    return ret;
}

void solve(int cs)
{
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    printf("Case #%d:\n",cs);
    scanf("%d",&m);
    while(m--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(x>y) swap(x,y);
        if(op) printf("%lld\n",query(1,1,n,x,y));
        else modify(1,1,n,x,y);
    }
    printf("\n");
}

int main()
{
    int cs=0;
    while(~scanf("%d",&n)) solve(++cs);
    return 0;
}
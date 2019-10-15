#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int n;
ll x;
pll p[105];

bool cmp(pll a,pll b)
{
    if(a.first-a.second!=b.first-b.second) return a.first-a.second>b.first-b.second;
    return a.first>b.first;
}

void solve()
{
    ll d,h,mx=0;
    scanf("%d%lld",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&d,&h),p[i]=make_pair(d,h),mx=max(mx,d);
    sort(p,p+n,cmp);
    if(mx>=x)
    {
        printf("1\n");
        return;
    }
    if(p[0].first-p[0].second<=0)
    {
        printf("-1\n");
        return;
    }
    ll ans=(x-mx)/(p[0].first-p[0].second)+1;
    if((x-mx)%(p[0].first-p[0].second)==0) ans--;
    printf("%lld\n",ans+1);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

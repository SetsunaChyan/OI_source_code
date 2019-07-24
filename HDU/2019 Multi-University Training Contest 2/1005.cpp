#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
int n;

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

void solve()
{
    ll ans=0,inv16=fp(16ll,mod-2),t=1;
    for(ll i=2;i<=n;i++)
    {
        ans+=i*(i-1)%mod,ans%=mod;
    }
    ans=ans*fp(3ll,mod-2)%mod*fp(n,mod-2)%mod;
    printf("%lld\n",ans);
}

int main()
{
    while(~scanf("%d",&n)) solve();
    return 0;
}

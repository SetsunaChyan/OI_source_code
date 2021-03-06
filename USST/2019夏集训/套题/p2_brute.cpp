#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
ll m,k,ans;

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
    ans=0;
    scanf("%lld%lld",&m,&k);
    for(ll i=0;i<k;i++)
        for(ll j=0;j<k;j++)
            if((i+j)%m==0) ans++;
    printf("%lld\n",ans*fp(k*k%mod,mod-2)%mod);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

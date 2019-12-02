#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll p[100005];

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
    ll a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",2ll*p[a-1]%mod*fp(p[b],mod-2)%mod*fp(p[a-b-1],mod-2)%mod);
}

int main()
{
    p[0]=1;
    for(int i=1;i<=100000;i++) p[i]=p[i-1]*i%mod;
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
ll n,m;

ll fp(ll x,ll y)
{
    ll ret=1%mod;
    x%=mod;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    printf("%lld",fp(fp(2,m)-1+mod,n));
    return 0;
}

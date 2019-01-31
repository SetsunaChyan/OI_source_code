#include <cstdio>

typedef long long ll;
const ll mod=19260817;
ll n,k;

int main()
{
    scanf("%lld%lld",&n,&k);
    ll ans=1,base=k+1;
    while(n)
    {
        if(n&1) ans=ans*base%mod;
        base=base*base%mod;
        n>>=1;
    }
    printf("%lld",ans);
    return 0;
}
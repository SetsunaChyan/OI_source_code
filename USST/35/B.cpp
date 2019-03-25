#include <cstdio>

typedef long long ll;

const ll mod=998244353;
ll n,x;

ll fp(ll a,ll b)
{
    ll ret=1,base=a%mod;
    while(b)
    {
        if(b&1) ret=ret*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld",&n,&x);
    if(x==1)
    {
        printf("%lld",(1+n)*n%mod*fp(2,mod-2)%mod);
        return 0;
    }
    printf("%lld",((n*n%mod-2*n%mod+3)*fp(2,n+1)+mod-6)%mod);
    return 0;
}
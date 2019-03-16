#include <cstdio>

typedef long long ll;
const ll mod=998244353;
ll n,m,l,ans=1;

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

inline ll inv(ll x){return fp(x,mod-2);}

int main()
{
    scanf("%lld%lld%lld",&n,&m,&l);
    for(ll i=n;i>n-m;i--) ans=ans*i%mod;
    for(ll i=2;i<=m;i++) ans=ans*inv(i)%mod;
    ans=ans*fp(n-m,l)%mod;
    printf("%lld",ans);
    return 0;
}
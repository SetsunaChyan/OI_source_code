#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+9;
ll n,m,k;

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

int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    ll tmp=m;
    m-=n/k*(k-1)+n%k;
    if(m<0) m=0;
    tmp-=k*m;
    ll ans=fp(2ll,m+1);
    ans=(ans+mod-2)%mod;
    printf("%lld",(ans*k+tmp)%mod);
    return 0;
}

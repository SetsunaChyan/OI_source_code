#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=998244353;
ll n,ans,a;
ll gao(ll a)
{
    ll t=a,c=1,ans=0;
    while(t*a<=n+1)
        ans=(ans+(t*a-t)*c)%mod,++c,t*=a;
    ans=(ans+(n-t+1)*c)%mod;
    return ans;
}
ll qpow(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)
            ans=ans*a%mod;
    return ans;
}
ll qmul(ll a,ll b)
{
    ll ans=0;
    for(;b;b>>=1,a=(a+a)%mod)
        if(b&1)
            ans=(ans+a)%mod;
    return ans;
}
ll f(ll x)
{
    ll a=(n+1)%mod*qmul(x,x+1)%mod*qpow(2,mod-2)%mod;
    ll b=qmul(qmul(x,x+1),2*x+1)*qpow(6,mod-2)%mod;
    return (a+mod-b)%mod;
}
void g()
{
    ll ans=0;
    for(ll a=2;a<=n;a++)
    {
        ll t=0;
        for(ll b=a;b<=n;b++)
            t+=floor(log(b)/log(a));
        ans+=a*t;
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%lld",&n);//g();
    for(a=2;a*a<=n;a++)
        ans=(ans+a*gao(a))%mod;
    ans=(ans+f(n)+mod-f(a-1))%mod;
    printf("%lld\n",ans);
    return 0;
}

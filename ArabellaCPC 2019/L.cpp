#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7,inv=5e8+4;
ll n,m,r,c;
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&r,&c);
    ll g1=__gcd(n,r),g2=__gcd(m,c);
    ll t1=n/g1,t2=m/g2;
    ll x=(g1-1)*m+g2;
    ll y=(n-1)*m+g2;
    ll a=t1*(x+y)/2;
    ll ans=t2*(2*a+(t2-1)*t2*g2)/2;
    printf("%lld %lld %lld %lld %lld %lld %lld\n",g1,g2,t1,t2,x,y,a);
    printf("%lld\n",ans);
    return 0;
}

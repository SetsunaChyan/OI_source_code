#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b;

void solve()
{
    scanf("%lld%lld",&a,&b);
    ll ans=0;a=abs(a-b);
    ans+=a/5,a%=5;
    ans+=a/2,a%=2;
    printf("%lld\n",ans+a);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

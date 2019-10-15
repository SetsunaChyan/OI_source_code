#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,n;

void solve()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    ll ans=0;
    if(2*a<=b) ans=n*a;
    else ans=b*(n/2)+(n%2)*a;
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,ans;

int main()
{
    scanf("%lld%lld",&n,&k);
    ans=n*k;
    for(ll l=1,r;l<=min(n,k);l=r+1)
    {
        r=min(n,k/(k/l));
        ans-=(k/r)*(r+l)*(r-l+1)/2;
    }
    printf("%lld",ans);
    return 0;
}

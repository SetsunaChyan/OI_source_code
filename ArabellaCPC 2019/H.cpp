#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,k;
    scanf("%lld %lld",&n,&k);
    ll ans=0;
    ans=max((ll)10,(ll)ceil((double)n/k)*5);
    printf("%lld\n",ans);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;

int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        ll ans=(n+1)/3*((m+1)/2)+(n-(n+1)/3*2>1)*((m+1)/3);
        swap(n,m);
        ans=max(ans,(n+1)/3*((m+1)/2)+(n-(n+1)/3*2>1)*((m+1)/3));
        printf("%lld\n",ans);
    }
    return 0;
}

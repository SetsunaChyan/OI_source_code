#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ans;

int main()
{
    scanf("%lld",&n);
    ans=n;
    for(ll i=2;i*i<=n;i++)
        while(n%i==0)
            ans+=n/i,n/=i;
    if(n!=1) ans++;
    printf("%lld",ans);
    return 0;
}

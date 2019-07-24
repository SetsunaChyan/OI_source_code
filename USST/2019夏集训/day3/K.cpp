#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s,l,r,ans=0;

int main()
{
    scanf("%lld",&s);
    for(ll n=1;n<=s;n++)
    {
        ll k=(2*s+n-n*n)/2/n;
        if(k<=0) break;
        if((2*k+n-1)*n==2*s)
            ans=max(ans,n);
    }
    ll k=(2*s+ans-ans*ans)/2/ans;
    printf("%lld %lld",k,k+ans-1);
    return 0;
}

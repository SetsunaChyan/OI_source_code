#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ans,x,qaq=1;

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&ans);
    for(int i=1;i<n;i++)
    {
        scanf("%lld",&x);
        ans=__gcd(x,ans);
    }
    if(ans==1)
    {
        printf("1");
        return 0;
    }
    for(ll i=2;i*i<=ans;i++)
    {
        if(ans%i==0)
        {
            ll cnt=1;
            while(ans%i==0)
            {
                cnt++;
                ans/=i;
            }
            qaq*=cnt;
        }
    }
    if(ans!=1) qaq*=2;
    printf("%lld",qaq);
    return 0;
}

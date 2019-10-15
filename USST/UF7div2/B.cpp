#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,mm=0x3f3f3f3f3f3f3f3fll,mx=0,c;

int main()
{
    scanf("%lld",&n);
    for(ll a=1;a*a<=n;a++)
    {
        if(n%a) continue;
        ll bc=n/a;
        for(ll b=1;b*b<=bc;b++)
        {
            if(bc%b) continue;
            c=bc/b;
            mm=min(mm,(a+1)*(b+2)*(c+2));
            mx=max(mx,(a+1)*(b+2)*(c+2));
        }
        bc=a;
        for(ll b=1;b*b<=bc;b++)
        {
            if(bc%b) continue;
            c=bc/b;
            mm=min(mm,(n/a+1)*(b+2)*(c+2));
            mx=max(mx,(n/a+1)*(b+2)*(c+2));
        }
    }
    printf("%lld %lld",mm-n,mx-n);
    return 0;
}

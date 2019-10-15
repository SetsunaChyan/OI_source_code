#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,x,y;

bool check(ll q)
{
    return q*x<=a&&q*y<=b;
}

int main()
{
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    ll k=__gcd(x,y);
    x/=k;y/=k;
    ll l=0,r=2e9;
    while(l<r)
    {
        ll m=l+r+1>>1;
        if(check(m)) l=m; else r=m-1;
    }
    printf("%lld %lld",l*x,l*y);
    return 0;
}

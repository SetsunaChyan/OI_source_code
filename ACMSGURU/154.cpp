#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,l,r;

int check(ll x)
{
    ll ret=0,k=5;
    while(k<=x)
        ret+=x/k,k*=5;
    return ret;
}

int main()
{
    scanf("%lld",&n);
    l=1,r=5*n;
    while(l<r)
    {
        ll m=l+r>>1;
        if(check(m)>=n) r=m; else l=m+1;
    }
    if(check(l)==n) printf("%lld",l); else printf("No solution");
    return 0;
}

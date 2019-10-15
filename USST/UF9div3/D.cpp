#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,r,n,k;

bool check(int x)
{
    ll ret=x;
    for(ll i=k;i<=x;i*=k)
        ret+=x/i;
    return ret>=n;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    l=1,r=1e9;
    while(l<r)
    {
        ll mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    printf("%lld",l);
    return 0;
}

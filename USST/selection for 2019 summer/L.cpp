#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200005],n,k,l,r,m;

bool check(ll x)
{
    ll last=0;
    for(int i=0;i<k;i++)
    {
        if(last+x/2+1<a[i]) return false;
        if(a[i]<=last)
            last=a[i]+x/2;
        else
            last=last+x/2+1;
    }
    if(last<n) return false;
    return true;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%lld",&a[i]);
    l=1;r=n<<2;
    while(l<r)
    {
        m=l+r>>1;
        if(check(m)) r=m; else l=m+1;
    }
    printf("%lld",l);
    return 0;
}
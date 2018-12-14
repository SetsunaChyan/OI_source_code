#include <cstdio>
#include <memory.h>

typedef long long ll;
ll n,t,a[2005],f[2005],q[2005];

inline ll min(ll a,ll b){return a<b?a:b;}

bool check(ll x)
{
    ll hd=0,ed=0;
    q[0]=0;
    f[0]=a[0];
    for(ll i=1;i<n;i++)
    {
        while(hd<ed&&q[hd]<i-x-1) hd++;
        if(i<=x)
            f[i]=a[i];
        else
            f[i]=f[q[hd]]+a[i];
        while(hd<=ed&&f[q[ed]]>f[i]) ed--;
        q[++ed]=i;
    }
    ll ans=0x3f3f3f3f3f3f3f3fll;
    for(ll i=n-x-1;i<n;i++)
        ans=min(ans,f[i]);
    if(ans<=t)
        return true;
    else
        return false;
}

int main()
{
    while(~scanf("%lld%lld",&n,&t)&&n&&t)
    {
        for(ll i=0;i<n;i++)
            scanf("%lld",&a[i]);
        ll l=0,r=n;
        while(l<r)
        {
            ll mid=(l+r)/2;
            if(check(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%lld",l);
    }
    return 0;
}
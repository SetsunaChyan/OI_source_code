#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005],k,l,r,mid,s1,s2,sum;
int n;

bool check1(ll x)
{
    ll s=0;
    for(int i=0;i<n;i++)
        if(x>a[i]) s+=x-a[i];
    return s<=k;
}

bool check2(ll x)
{
    ll s=0;
    for(int i=0;i<n;i++)
        if(x<a[i]) s+=a[i]-x;
    return s<=k;
}

void solve()
{
    sum=0;
    for(int i=0;i<n;i++)
        scanf("%lld",a+i),sum+=a[i];
    l=0;r=1e10;
    while(l<r)
    {
        mid=l+r>>1;
        if(check1(mid)) l=mid+1; else r=mid;
    }
    s1=l-1;
    l=0;r=1e10;
    while(l<r)
    {
        mid=l+r+1>>1;
        if(check2(mid)) r=mid-1; else l=mid;
    }
    s2=l+1;
    if(s2>s1) printf("%lld\n",s2-s1);
    else if(sum%n==0) printf("0\n");
    else printf("1\n");
}

int main()
{
    while(~scanf("%d%lld",&n,&k)) solve();
    return 0;
}

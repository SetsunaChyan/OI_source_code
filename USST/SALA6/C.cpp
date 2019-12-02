#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[200005],ans=2e18;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
        scanf("%lld",a+i);
    sort(a,a+2*n);
    for(int i=0;i<=n;i++)
    {
        ll x=a[i+n-1]-a[i],y;
        if(i==0) y=a[2*n-1]-a[n];
        else if(i==n) y=a[n-1]-a[0];
        else y=a[2*n-1]-a[0];
        ans=min(ans,x*y);
    }
    printf("%lld",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll sum,ans,a[1000005],b[1000005];

void solve()
{
    sum=ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",a+i,b+i),sum+=b[i];
    for(int i=0;i<n;i++)
        ans+=min(a[i],sum-b[i]);
    printf("%lld\n",min(ans,sum));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

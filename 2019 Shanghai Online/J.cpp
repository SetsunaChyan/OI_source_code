#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n,a[305],sum;
ll dp[305*505];

void solve()
{
    sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),sum+=a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=0;i<=sum;i++) dp[i]=0;
    dp[0]=1;
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=sum;j>=a[i];j--)
        {
            dp[j]+=dp[j-a[i]],dp[j]%=mod;
            if(2*j>=sum&&j-a[i]<=sum-j) ans+=dp[j-a[i]],ans%=mod;
        }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[300005],b[300005],dp[300005][3];

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",a+i,b+i);
    for(int i=0;i<n;i++)
        dp[i][0]=dp[i][1]=dp[i][2]=1e18+5;
    dp[0][0]=0,dp[0][1]=b[0],dp[0][2]=b[0]<<1;
    for(int i=1;i<n;i++)
    {
        /*
        if(a[i]==a[i-1])
            dp[i][0]=dp[i-1][1],dp[i][1]=dp[i-1][0]+b[i];
        else if(a[i]==a[i-1]+1)
            dp[i][0]=dp[i-1][0],dp[i][1]=min(dp[i-1][1],dp[i-1][0])+b[i];
        else if(a[i]+1==a[i-1])
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]),dp[i][1]=dp[i-1][1]+b[i];
        else
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]),dp[i][1]=min(dp[i-1][0],dp[i-1][1])+b[i];
        printf("%lld %lld\n",dp[i][0],dp[i][1]);*/
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                if(a[i]+j==a[i-1]+k) continue;
                dp[i][j]=min(dp[i][j],dp[i-1][k]+j*b[i]);
            }
        //printf("qaq %lld %lld %lld\n",dp[i][0],dp[i][1],dp[i][2]);
    }
    printf("%lld\n",min(min(dp[n-1][2],dp[n-1][0]),dp[n-1][1]));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

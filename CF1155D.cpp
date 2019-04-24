#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[300005][3],ans=0,x,a[300005];
int n;

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%lld",&n,&x);
    a[0]=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][0]+a[i],dp[i][0]);
        dp[i][1]=max(dp[i-1][0]+x*a[i],dp[i][1]);
        dp[i][1]=max(dp[i-1][1]+x*a[i],dp[i][1]);
        dp[i][2]=max(dp[i-1][1]+a[i],dp[i][2]);
        dp[i][2]=max(dp[i-1][2]+a[i],dp[i][2]);
    }
    for(int i=1;i<=n;i++) 
        for(int j=0;j<3;j++)
            ans=max(ans,dp[i][j]);
    printf("%lld",ans);
    return 0;
}
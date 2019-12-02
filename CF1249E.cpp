#include <bits/stdc++.h>
using namespace std;

int n,c,a[200005],b[200005],dp[200005][2];

int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<n;i++)
        scanf("%d",a+i);
    for(int i=1;i<n;i++)
        scanf("%d",b+i);
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0,dp[1][1]=c;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][1],dp[i-1][0])+a[i-1];
        dp[i][1]=min(dp[i-1][0]+c,dp[i-1][1])+b[i-1];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",min(dp[i][0],dp[i][1]));
    return 0;
}

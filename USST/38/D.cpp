#include <cstdio>
#include <memory.h>

int n,dp[205][205];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&dp[i][i]);
    dp[0][0]=dp[n+1][n+1]=1;

    for(int i=3;i<=n+2;i++)
        for(int j=0;j<=n+2-i;j++)
            for(int k=j+1;k<=j+i-2;k++)
                dp[j][j+i-1]=max(dp[j][j+i-1],dp[j][k]+dp[k][k]*dp[j][j]*dp[j+i-1][j+i-1]+dp[k][j+i-1]);
    printf("%d",dp[0][n+1]);
    return 0;
}
#include <cstdio>

typedef long long ll;
ll dp[50][2];
int n;

int main()
{
    scanf("%d",&n);
    dp[0][0]=2,dp[0][1]=0;
    for(int i=1;i<n;i++)
    {
        dp[i][1]=dp[i-1][0];
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
    }
    printf("%lld",dp[n-1][0]+dp[n-1][1]);
    return 0;
}
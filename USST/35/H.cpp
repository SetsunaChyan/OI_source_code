#include <cstdio>
#include <memory.h>

int dp[20005],n,m;

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=y;j<=n;j++)
            dp[j]=dp[j]<dp[j-y]+x?dp[j-y]+x:dp[j];
    }
    printf("%d",dp[n]);
    return 0;
}
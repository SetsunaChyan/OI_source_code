#include <cstdio>
#include <memory.h>

int dp[15][15];

int main()
{
    int n,m;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<=10;i++)
        for(int j=0;j<=10;j++)
        {
            if(i) dp[i][j]+=dp[i-1][j];
            if(j) dp[i][j]+=dp[i][j-1];
        }
    while(~scanf("%d%d",&n,&m))
        printf("%d\n",dp[n][m]);
    return 0;
}
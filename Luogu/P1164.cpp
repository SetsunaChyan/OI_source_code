#include <cstdio>
#include <memory.h>

int m,n,dp[10001];

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=m;j>=x;j--)
            dp[j]+=dp[j-x];
    }
    printf("%d",dp[m]);
    return 0;
}
#include <cstdio>
#include <memory.h>

int x,dp[20005],n,v;

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    scanf("%d%d",&v,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        for(int j=v;j>=x;j--)
            dp[j]|=dp[j-x];
    }
    for(int i=v;i>=0;i--)
        if(dp[i])
        {
            printf("%d",v-i);
            return 0;
        }
    return 0;
}
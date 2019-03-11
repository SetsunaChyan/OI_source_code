#include <cstdio>
#include <memory.h>

int n,m,t,dp[201][201];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=m;j>=x;j--)
            for(int k=t;k>=y;k--)
                dp[j][k]=max(dp[j][k],dp[j-x][k-y]+1);
    }
    printf("%d",dp[m][t]);
    return 0;
}
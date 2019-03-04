#include <cstdio>
#include <memory.h>

int t,m,dp[100001];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&t,&m);
    for(int i=0;i<m;i++)
    {
        int x,c;
        scanf("%d%d",&x,&c);
        for(int j=x;j<=t;j++)
            dp[j]=max(dp[j-x]+c,dp[j]);
    }
    int ans=0;
    printf("%d",dp[t]);
    return 0;
}
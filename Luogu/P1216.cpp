#include <cstdio>
#include <memory.h>

int n,a[1000][1000],dp[1000][1000];

inline int max(int a,int b){return a>b?a:b;}

int main()
{  
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
        a[i][i+1]=0;
    }
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i][0];
        for(int j=1;j<=i;j++)
            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[n-1][i]);
    printf("%d",ans);
    return 0;
}
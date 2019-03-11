#include <cstdio>
#include <memory.h>

int n,m,dp[205][205],a[205][205],ans=-0x3f3f3f3f;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(a,0,sizeof(a));
    memset(dp,0xc0,sizeof(dp));
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    dp[m][n/2]=0;
    for(int i=m-1;i>=0;i--)
        for(int j=0;j<n;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i+1][j]+a[i][j]);
            if(j) dp[i][j]=max(dp[i][j],dp[i+1][j-1]+a[i][j]);
            if(j<n-1) dp[i][j]=max(dp[i][j],dp[i+1][j+1]+a[i][j]);
        }
    for(int i=0;i<n;i++)
        ans=max(ans,dp[0][i]);
    printf("%d",ans);
    return 0;
}
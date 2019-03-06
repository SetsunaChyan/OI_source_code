#include <cstdio>
#include <memory.h>

const int Q=5000;
int n,dp[1001][10001],a[1001],b[1001],ans;

inline int min(int a,int b){return a<b?a:b;}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    scanf("%d",&n);
    dp[0][Q]=0;
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i+1],&b[i+1]);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=10000;j++)
        {
            if(j-a[i]+b[i]>=0&&j-a[i]+b[i]<=10000) dp[i][j]=min(dp[i][j],dp[i-1][j-a[i]+b[i]]+1);
            if(j+a[i]-b[i]>=0&&j+a[i]-b[i]<=10000) dp[i][j]=min(dp[i][j],dp[i-1][j+a[i]-b[i]]);
        }
    }
    for(int i=0;i<=5000;i++)
        if(dp[n][Q+i]<1000||dp[n][Q-i]<1000)
        {
            ans=min(dp[n][Q+i],dp[n][Q-i]);
            break;
        }
    printf("%d",ans);
    return 0;
}
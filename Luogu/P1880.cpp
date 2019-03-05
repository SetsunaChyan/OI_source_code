#include <cstdio>
#include <memory.h>

int dp[200][200],n,a[200],pre[201],ans;

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    scanf("%d",&n);
    pre[0]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        pre[i+1]=pre[i]+a[i];
    }
    for(int i=n;i<2*n;i++)
    {
        a[i]=a[i-n];
        pre[i+1]=pre[i]+a[i];
    }

    for(int i=0;i<2*n;i++)
        dp[i][i]=0;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=2*n-i;j++)
            for(int k=j;k<j+i-1;k++)
                dp[j][j+i-1]=min(dp[j][k]+dp[k+1][j+i-1]+pre[j+i]-pre[j],dp[j][j+i-1]);
    ans=0x3f3f3f3f;
    for(int i=0;i<n;i++)
        ans=min(ans,dp[i][i+n-1]);
    printf("%d",ans);
    memset(dp,0,sizeof(dp));
    for(int i=2;i<=n;i++)
        for(int j=0;j<=2*n-i;j++)
            for(int k=j;k<j+i-1;k++)
                dp[j][j+i-1]=max(dp[j][k]+dp[k+1][j+i-1]+pre[j+i]-pre[j],dp[j][j+i-1]);
    ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i][i+n-1]);
    printf("\n%d",ans);
    return 0;
}
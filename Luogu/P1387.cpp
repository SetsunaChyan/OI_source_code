#include <cstdio>
#include <memory.h>

int n,m,a[105][105],h[105][105],w[105][105],dp[105][105],ans=0;

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
    {
        h[i][0]=a[i][0];
        for(int j=1;j<m;j++)
            h[i][j]=a[i][j]?h[i][j-1]+1:0;
    }
    for(int i=0;i<m;i++)
    {
        w[0][i]=a[0][i];
        for(int j=1;j<n;j++)
            w[j][i]=a[j][i]?w[j-1][i]+1:0;
    }
    dp[0][0]=a[0][0];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(i&&j) dp[i][j]=min(dp[i-1][j-1]+1,min(h[i][j],w[i][j])); else dp[i][j]=a[i][j];
            ans=max(dp[i][j],ans);
        }
    printf("%d",ans);
    return 0;
}
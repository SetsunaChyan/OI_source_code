#include <cstdio>
#include <memory.h>

int n,m,a[2505][2505],w[2505][2505],h[2505][2505],dp[2505][2505],ans=0;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
    {
        w[i][0]=0;
        for(int j=0;j<m-1;j++)
            if(a[i][j]) w[i][j+1]=0; else w[i][j+1]=w[i][j]+1;
    }
    for(int i=0;i<m;i++)
    {
        h[0][i]=0;
        for(int j=0;j<n-1;j++)
            if(a[j][i]) h[j+1][i]=0; else h[j+1][i]=h[j][i]+1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]) 
            {
                dp[i][j]=1;
                if(i&&j) dp[i][j]=min(dp[i-1][j-1],min(h[i][j],w[i][j]))+1;
            }
            ans=max(ans,dp[i][j]); 
        }

    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        w[i][m-1]=0;
        for(int j=m-1;j>0;j--)
            if(a[i][j]) w[i][j-1]=0; else w[i][j-1]=w[i][j]+1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]) 
            {
                dp[i][j]=1;
                if(i&&j<m-1) dp[i][j]=min(dp[i-1][j+1],min(h[i][j],w[i][j]))+1;
            }
            ans=max(ans,dp[i][j]); 
        }

    printf("%d",ans);
    return 0;
}
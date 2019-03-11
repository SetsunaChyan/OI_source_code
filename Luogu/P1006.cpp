#include <cstdio>
#include <memory.h>

int m,n,dp[110][55][55],a[55][55];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0xc0,sizeof(dp));
    dp[0][0][0]=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n+m-2;i++)
        for(int x1=0;x1<n;x1++)
            for(int x2=0;x2<n;x2++)
            {
                if(x1==x2&&i!=n+m-2) continue;
                if(i-x1>=m||i-x2>=m) continue;
                //RR
                if(x1&&x2&&i-x1>=0&&i-x2>=0) dp[i][x1][x2]=max(dp[i][x1][x2],dp[i-1][x1-1][x2-1]+a[i-x1][x1]+a[i-x2][x2]);
                //RD
                if(x1&&i-x2>0) dp[i][x1][x2]=max(dp[i][x1][x2],dp[i-1][x1-1][x2]+a[i-x1][x1]+a[i-x2][x2]);
                //DR
                if(x2&&i-x1>0) dp[i][x1][x2]=max(dp[i][x1][x2],dp[i-1][x1][x2-1]+a[i-x1][x1]+a[i-x2][x2]);
                //DD
                if(i-x2>0&&i-x1>0) dp[i][x1][x2]=max(dp[i][x1][x2],dp[i-1][x1][x2]+a[i-x1][x1]+a[i-x2][x2]);
            }
    printf("%d",dp[n+m-2][n-1][n-1]);
    return 0;
}
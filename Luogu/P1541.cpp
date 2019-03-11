#include <cstdio>
#include <memory.h>

int m,n,c[4],dp[41][41][41][41],a[355];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(c,0,sizeof(c));
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        c[x-1]++;
    }
    dp[0][0][0][0]=a[0];
    for(int i=0;i<=c[0];i++)
        for(int j=0;j<=c[1];j++)
            for(int k=0;k<=c[2];k++)
                for(int l=0;l<=c[3];l++)
                {
                    int up=i+j*2+k*3+l*4;
                    if(i) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+a[up]);
                    if(j) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+a[up]);
                    if(k) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+a[up]);
                    if(l) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+a[up]);
                }
    printf("%d",dp[c[0]][c[1]][c[2]][c[3]]);
    return 0;
}
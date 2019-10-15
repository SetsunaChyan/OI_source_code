#include <bits/stdc++.h>
using namespace std;

int ans=0xc0c0c0c0,dp[105][105],from[105][105],n,m,v[105][105];

void print(int x,int y)
{
    if(x==0) return;
    print(x-1,from[x][y]);
    printf("%d ",y);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&v[i][j]);
    memset(dp,0xc0,sizeof(dp));
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=m;j++)
        {
            int mx=0xc0c0c0c0,num;
            for(int k=i-1;k<j;k++)
                if(dp[i-1][k]>mx) mx=dp[i-1][k],num=k;
            dp[i][j]=mx+v[i][j],from[i][j]=num;
        }
    int num;
    for(int i=n;i<=m;i++) if(dp[n][i]>ans) ans=dp[n][i],num=i;
    printf("%d\n",ans);
    print(n,num);
    return 0;
}

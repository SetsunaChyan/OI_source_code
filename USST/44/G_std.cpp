#include <bits/stdc++.h>
using namespace std;

int dp[55][505],m,n,s;

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&n,&m,&s);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=m;i>=1;i--)
            for(int j=s;j>=x;j--)
                dp[i][j]=max(dp[i][j],dp[i-1][j-x]+y);
    }
    printf("%d",dp[m][s]);
    return 0;
}
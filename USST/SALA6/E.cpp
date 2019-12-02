#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[5005],dp[5005][2505][2];

inline int cal(int x,int y){return max(0,y-x+1);}

int main()
{
    scanf("%d",&n);
    m=(n+1)/2;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    a[0]=0x3f3f3f3f;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=dp[1][1][1]=dp[1][0][0]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i][0][0]=dp[i-1][0][0];
        for(int j=1;j<=m;j++)
            {
                dp[i][j][1]=min(dp[i-2][j-1][0]+cal(a[i],a[i-1]),dp[i-2][j-1][1]+cal(min(a[i-2],a[i]),a[i-1]));
                dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]+cal(a[i-1],a[i]));
            }
    }
    for(int i=1;i<=m;i++) printf("%d ",min(dp[n][i][0],dp[n][i][1]));
    return 0;
}

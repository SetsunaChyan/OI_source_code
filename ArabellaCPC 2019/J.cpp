#include <bits/stdc++.h>
using namespace std;
char s[100005];
int n,dp[100005][2];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)s[i]-='0';
    dp[n+1][1]=1e9;
    for(int i=n;i>=1;i--)
        dp[i][0]=min(dp[i+1][0]+s[i],dp[i+1][1]+(s[i]+1>=10?1:s[i]+1)),
        dp[i][1]=min(dp[i+1][0]+10-s[i],dp[i+1][1]+9-s[i]);
        //printf("%d:%d %d\n",i,dp[i][0],dp[i][1]);
    printf("%d\n",min(dp[1][0],dp[1][1]+1));
    return 0;
}

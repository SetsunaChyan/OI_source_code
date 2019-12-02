#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,dp[1005][1005];
char s[1005],t[1005];

int main()
{
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i]==t[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    printf("%d",dp[n][m]);
    return 0;
}

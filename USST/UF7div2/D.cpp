#include <bits/stdc++.h>
using namespace std;

int dp[105][55][2],l,n;
char s[105];

int main()
{
    scanf("%s%d",s+1,&n);
    l=strlen(s+1);
    memset(dp,0xc0,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=l;i++)
    {
        if(s[i]=='T') dp[i][0][0]=dp[i-1][0][1],dp[i][0][1]=dp[i-1][0][0];
        if(s[i]=='F') dp[i][0][0]=dp[i-1][0][0]+1,dp[i][0][1]=dp[i-1][0][1]-1;
        for(int j=1;j<=n;j++)
        {
            if(s[i]=='T') dp[i][j][0]=max(dp[i-1][j-1][0]+1,dp[i-1][j][1]);
            if(s[i]=='T') dp[i][j][1]=max(dp[i-1][j][0],dp[i-1][j-1][1]-1);
            if(s[i]=='F') dp[i][j][0]=max(dp[i-1][j][0]+1,dp[i-1][j-1][1]);
            if(s[i]=='F') dp[i][j][1]=max(dp[i-1][j][1]-1,dp[i-1][j-1][0]);
            if(j>=2) dp[i][j][0]=max(dp[i][j][0],dp[i][j-2][0]);
            if(j>=2) dp[i][j][1]=max(dp[i][j][1],dp[i][j-2][1]);
        }
    }
    int ans=max(dp[l][n][0],dp[l][n][1]);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    /*for(int i=1;i<=l;i++)
    {
        if(s[i]=='T') dp[i][0][0]=dp[i-1][0][1],dp[i][0][1]=dp[i-1][0][0];
        if(s[i]=='F') dp[i][0][0]=dp[i-1][0][0]-1,dp[i][0][1]=dp[i-1][0][1]+1;
        for(int j=1;j<=n;j++)
        {
            if(s[i]=='T') dp[i][j][0]=min(dp[i-1][j-1][0]+1,dp[i-1][j][1]);
            if(s[i]=='T') dp[i][j][1]=min(dp[i-1][j][0],dp[i-1][j-1][1]-1);
            if(s[i]=='F') dp[i][j][0]=min(dp[i-1][j][0]+1,dp[i-1][j-1][1]);
            if(s[i]=='F') dp[i][j][1]=min(dp[i-1][j][1]-1,dp[i-1][j-1][0]);
            if(j>=2) dp[i][j][0]=min(dp[i][j][0],dp[i][j-2][0]);
            if(j>=2) dp[i][j][1]=min(dp[i][j][1],dp[i][j-2][1]);
        }
    }*/
    for(int i=1;i<=l;i++)
    {
        if(s[i]=='T') dp[i][0][0]=dp[i-1][0][1],dp[i][0][1]=dp[i-1][0][0];
        if(s[i]=='F') dp[i][0][0]=dp[i-1][0][0]+1,dp[i][0][1]=dp[i-1][0][1]-1;
        for(int j=1;j<=n;j++)
        {
            if(s[i]=='T') dp[i][j][0]=min(dp[i-1][j-1][0]+1,dp[i-1][j][1]);
            if(s[i]=='T') dp[i][j][1]=min(dp[i-1][j][0],dp[i-1][j-1][1]-1);
            if(s[i]=='F') dp[i][j][0]=min(dp[i-1][j][0]+1,dp[i-1][j-1][1]);
            if(s[i]=='F') dp[i][j][1]=min(dp[i-1][j][1]-1,dp[i-1][j-1][0]);
            if(j>=2) dp[i][j][0]=min(dp[i][j][0],dp[i][j-2][0]);
            if(j>=2) dp[i][j][1]=min(dp[i][j][1],dp[i][j-2][1]);
        }
    }
    ans=max(ans,-min(dp[l][n][0],dp[l][n][1]));
    printf("%d",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,p,len[1005],dp[1005][1005],pos[1005][1005],rm[1005];
vector<int> has[1005];

int main()
{
    memset(pos,-1,sizeof(pos));
    scanf("%d%d",&n,&p);
    for(int i=1;i<n;i++) scanf("%d",len+i),len[i]%=n-i+1;
    for(int i=1;i<=n;i++) has[0].push_back(i),pos[0][i]=i-1;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&rm[i]);
        for(auto q:has[i-1])
            if(rm[i]!=q) has[i].push_back(q);
        for(int j=0;j<has[i].size();j++) pos[i][has[i][j]]=j;
    }
    dp[0][p]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!dp[i-1][j]) continue;
            dp[i][has[i-1][(pos[i-1][j]+len[i])%(n-i+1)]]=1;
            dp[i][has[i-1][(pos[i-1][j]-len[i]+n-i+1)%(n-i+1)]]=1;
        }
        dp[i][rm[i]]=0;
    }
    if(dp[n-1][has[n-1][0]]) printf("Yes");
    else printf("No");
    return 0;
}

/*
2 1
1
2
*/

#include <bits/stdc++.h>
using namespace std;
int dp[250],n,a[21]={4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,14,14,14,16,18};
int main()
{
    int _;
    scanf("%d",&_);
    memset(dp,0xc0,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<21;i++)
        for(int j=200;j>=a[i];j--)
            dp[j]=max(dp[j],dp[j-a[i]]+1);
    while(_--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n]<0?-1:21-dp[n]);
    }
    return 0;
}
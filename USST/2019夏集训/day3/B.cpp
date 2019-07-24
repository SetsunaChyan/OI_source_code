#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1000000000ll;
ll dp[1005][2],ans=0;
int n,k;

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&k,&n);
    dp[1][0]=1;
    for(int i=2;i<=k;i++)
    {
        dp[i][0]=(n-1)*dp[i-1][0]%mod;
        dp[i][1]=(dp[i-1][0]+n*dp[i-1][1]%mod)%mod;
    }
    printf("%lld\n",dp[k][1]*n%mod);
    return 0;
}

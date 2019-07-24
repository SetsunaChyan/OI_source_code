#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n,m;
ll dp[500005][2];
// 0 不一样
// 1 一样

void solve()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    if(m==2)
    {
        printf("0\n");
        return;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=m-3;
    dp[0][1]=1;
    for(int i=1;i<n;i++)
    {
        dp[i][0]=(max(0ll,(m-3)*dp[i-1][0]%mod)+max(0ll,(m-2)*dp[i-1][1]%mod))%mod;
        dp[i][1]=(max(0ll,dp[i-1][0]%mod)+max(0ll,dp[i-1][0]%mod))%mod;
    }
    ll ans=dp[n-1][0]+dp[n-1][1];
    printf("%lld\n",ans);
}

int main()
{
    int _;
    while(_--) solve();
    return 0;
}

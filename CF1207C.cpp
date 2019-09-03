#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=0x3f3f3f3f3f3f3f3fll;
int n;
ll a,b,dp[200005][2];
char s[200005];

void solve()
{
    scanf("%d%lld%lld",&n,&a,&b);
    scanf("%s",s+1);
    dp[0][0]=b;
    dp[0][1]=inf;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')
        {
            dp[i][1]=min(dp[i-2][0]+3*a+4*b,dp[i-1][1]+a+2*b);
            dp[i][0]=inf;
        }
        else
        {
            dp[i][1]=min(dp[i-1][1],dp[i-1][0]+a)+a+2*b;
            dp[i][0]=min(dp[i-1][1]+a,dp[i-1][0])+a+b;
            if(s[i+1]=='1') dp[i][0]=inf;
        }
    }
    printf("%lld\n",dp[n][0]);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

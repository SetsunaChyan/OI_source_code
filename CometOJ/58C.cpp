#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll k,a[100005],b[100005],dp[100005][3],ans,s;

int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",a+i,b+i);
    for(int i=1;i<=n;i++)
        b[i]*=a[i+1];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        s+=b[i];
        dp[i][0]=dp[i-1][0]+b[i];
        dp[i][1]=min(dp[i-1][0]+(k-1)*b[i-1],dp[i-1][1])+k*k*b[i];
        dp[i][2]=min(dp[i-1][1]+(k-1)*b[i],dp[i-1][2])+b[i];
    }
    ans=min(dp[n][0],dp[n][1]);
    ans=min(dp[n][2],ans);
    for(int i=1;i<=n+1;i++)
        ans=min(ans,s+(k-1)*b[i]+(k-1)*b[i-1]);
    printf("%lld",ans);
    return 0;
}

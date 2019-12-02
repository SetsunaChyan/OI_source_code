#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=998244353;
int n,k,a[1005];
ll dp[1005][1005];
int main()
{
    scanf("%d%d",&n,&k);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    vector<int>v;
    v.push_back(0);
    for(int i=1;i<=n;)
    {
        int st=i;
        while(i<=n&&a[st]==a[i])++i;
        v.push_back(i-st);
    }
    n=v.size();
    for(int i=1;i<n;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=k;j++)
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*v[i])%mod;
    }
    printf("%lld\n",dp[n-1][k]);
    return 0;
}

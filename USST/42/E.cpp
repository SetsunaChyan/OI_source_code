#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5005;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n;
ll dp[MAXN][MAXN],mp[MAXN],a[MAXN],h[MAXN];
pair<ll,int> p[MAXN];

void dis()
{
    sort(p,p+n);
    mp[0]=0;
    int k=1;
    for(int i=0;i<n;i++)
    {
        if(i&&p[i].first!=p[i-1].first) k++;
        a[p[i].second]=k;
        mp[k]=p[i].first;
    }
}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&h[i]);
        p[i]=make_pair(h[i],i);
    }
    dis();
    for(int i=0;i<a[0];i++)
        dp[0][i]=mp[i]+1;
    dp[0][a[0]]=h[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=a[i];j++)
        {
            if(mp[j]<h[i]&&mp[j]<=h[i-1]) dp[i][j]=dp[i-1][j]+1;
            if(mp[j]<h[i]&&mp[j]>h[i-1]) dp[i][j]=dp[i-1][a[i-1]]+mp[j]-h[i-1]+1;
            if(mp[j]==h[i]&&mp[j]<=h[i-1]) dp[i][j]=dp[i-1][j];
            if(mp[j]==h[i]&&mp[j]>h[i-1]) dp[i][j]=dp[i-1][a[i-1]]+mp[j]-h[i-1];
        }
        for(int j=a[i]-1;j>=0;j--)
            dp[i][j]=min(dp[i][j+1],dp[i][j]);
    }
    ll ans=INF;
    for(int i=0;i<=a[n-1];i++)
        ans=min(ans,dp[n-1][i]);
    printf("%lld",ans);
    return 0;
}
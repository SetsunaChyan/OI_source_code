#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int n,t[2005];
ll dp[2005][4005],c[2005];
pll p[2005];

bool cmp(pll a,pll b)
{
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}

int main()
{
    scanf("%d",&n);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        p[i]=make_pair(y,x);
    }
    for(int i=0;i<=2000;i++)
        dp[0][i]=0;
    //sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=4000;j>=0;j--)
        {
            if(j>=p[i].second) dp[i][j]=min(dp[i][j],dp[i-1][j-p[i].second]+p[i].first);
            if(j<4000) dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
        }
    }
    ll ans=0x3f3f3f3f3f3f3f3fll;
    for(int i=2000;i<=4000;i++)
        ans=min(dp[n][i],ans);//,printf("%lld ",dp[n][i]);
    printf("%lld\n",ans);
    //printf("%lld",dp[n][0]);
    return 0;
}

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
        if(!i&&p[i].first!=p[i-1].first) k++;
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
    for(int i=0;i<h[0];i++)
        dp[0][i]=i+1;
    dp[0][h[0]]=h[0];
    for(int i=1;i<n;i++)
    {
        //dp[i][j]表示前i根栅栏涂完且第i根栅栏至少涂j次横着的最少次数
        for(int j=0;j<=h[i];j++)
        {
            if(j<h[i]&&j<=h[i-1]) dp[i][j]=dp[i-1][j]+1;
            if(j<h[i]&&j>h[i-1]) dp[i][j]=dp[i-1][h[i-1]]+j-h[i-1]+1;
            if(j==h[i]&&j<=h[i-1]) dp[i][j]=dp[i-1][j];
            if(j==h[i]&&j>h[i-1]) dp[i][j]=dp[i-1][h[i-1]]+j-h[i-1];
        }
        //上面跑完的是正好涂j次的最少次数 反着取一下min就是至少j次
        for(int j=h[i]-1;j>=0;j--)
            dp[i][j]=min(dp[i][j+1],dp[i][j]);
    }
    //debug
    ll maxh=0;
    for(int i=0;i<n;i++) maxh=max(maxh,h[i]);
    for(int j=maxh;j>=0;j--)
    {
        for(int i=0;i<n;i++)
            if(j<=h[i]) printf("%4lld ",dp[i][j]); else printf("     ");
        printf("\n");
    }   
    //debug


    ll ans=INF;
    for(int i=0;i<=h[n-1];i++)
        ans=min(ans,dp[n-1][i]);
    for(int i=n-2;i>=0;i--)
    {
        if(h[i]<h[i+1]) break;
        for(int j=h[i+1];j<=h[i];j++)
            ans=min(ans,dp[i][j]);
    }
    printf("%lld",ans);
    return 0;
}

/*
10
1 1 2 2 4 4 4 2 2 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll l[200005],r[200005],dp[200005][2];
vector<int> e[200005];

void dfs(int now,int fa)
{
    //dp[now][0]=l[now];
    //dp[now][1]=r[now];
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs(to,now);
        dp[now][0]+=max(abs(l[now]-l[to])+dp[to][0],abs(l[now]-r[to])+dp[to][1]);
        dp[now][1]+=max(abs(r[now]-l[to])+dp[to][0],abs(r[now]-r[to])+dp[to][1]);
    }
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=0;
    for(int i=1,u,v;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&l[i],&r[i]);
    dfs(1,1);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

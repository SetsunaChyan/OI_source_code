#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll mm=0x3f3f3f3f3f3f3f3fll,dp[16005],son[16005];
vector<int> e[16005],ans;

void dfs1(int now,int fa)
{
    son[now]=1;
    dp[now]=0;
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs1(to,now);
        son[now]+=son[to];
        dp[now]+=dp[to]+1;
    }
}

void dfs2(int now,int fa)
{
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dp[to]=dp[now]-2*son[to]+n;
        dfs2(to,now);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
    dfs1(1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++) mm=min(dp[i],mm);
    for(int i=1;i<=n;i++) if(dp[i]==mm) ans.push_back(i);
    dfs1(ans[0],ans[0]);
    mm=0;
    for(auto to:e[ans[0]]) mm=max(mm,son[to]);
    printf("%lld %d\n",mm,(int)ans.size());
    for(auto p:ans) printf("%d ",p);
    return 0;
}

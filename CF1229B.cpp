#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int fa[100005],pa[100005],deg[100005],n;
ll a[100005],ans,dep[100005];
vector<int> e[100005];

void dfs1(int now,int fat)
{
    dep[now]=dep[fat]+1;
    fa[now]=fat;
    if(a[now]==a[fat]) pa[now]=pa[fat];
    else pa[now]=now;
    for(auto to:e[now])
    {
        if(to==fat) continue;
        dfs1(to,now);
    }
}

void dfs(int now,ll gcd)
{
    if(now==0) return;
    if(gcd==1)
    {
        ans+=dep[now],ans%=mod;
        return;
    }
    ans+=(dep[pa[now]]-dep[now]+1)%mod*gcd%mod,ans%=mod;
    dfs(fa[pa[now]],__gcd(gcd,a[fa[pa[now]]]));
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=0,u,v;i<n-1;i++)
        scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
    pa[1]=1;
    dfs1(1,1);
    fa[1]=0;
    for(int i=1;i<=n;i++) dfs(i,a[i]);
    printf("%lld",ans);
    return 0;
}

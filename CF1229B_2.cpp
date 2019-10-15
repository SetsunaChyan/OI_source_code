#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int fa[100005],pa[100005],deg[100005],n;
ll a[100005],ans,dep[100005],gg[100005];
vector<int> e[100005];

void dfs1(int now,int fat,ll gcd)
{
    dep[now]=dep[fat]+1;
    fa[now]=fat;
    if(__gcd(a[now],gcd)==a[now]) pa[now]=pa[fat];
    else pa[now]=fa[now],gcd=a[now];
    gg[now]=gcd;
    for(auto to:e[now])
    {
        if(to==fat) continue;
        dfs1(to,now,gcd);
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
    ans+=(dep[now]-dep[pa[now]])%mod*gcd%mod,ans%=mod;
    dfs(pa[now],__gcd(gcd,a[pa[now]]));
}

int main()
{
    //freopen("data.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=0,u,v;i<n-1;i++)
        scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
    //[0]=-1;
    dfs1(1,0,a[1]);
    for(int i=1;i<=n;i++) dfs(i,a[i]),printf("%d %d\n",i,pa[i]);
    printf("%lld",ans);
    return 0;
}

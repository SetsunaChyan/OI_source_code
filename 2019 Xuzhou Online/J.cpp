#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n,dep[1000005],mx;
vector<int> e[1000005];
ll p[1000005];

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

void dfs(int now,int fa,int dp)
{
    dep[now]=dp;
    mx=max(mx,dp);
    for(auto to:e[now])
        if(to!=fa) dfs(to,now,dp+1);
}

void dfs2(int now,int fa)
{
    if(dep[now]==mx)
    {
        p[now]=1;
        return;
    }
    ll son=e[now].size()-1;
    ll qaq=0;
    if(now==1) son++;
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs2(to,now);
        qaq+=(1-p[to]+mod),qaq%=mod;
    }
    qaq=qaq*fp(son,mod-2)%mod;
    p[now]=(1-fp(qaq,son)+mod)%mod;
}

int main()
{
    scanf("%d",&n);
    for(int i=1,v,u;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1,1);
    dfs2(1,1);
    printf("%lld",p[1]);
    return 0;
}

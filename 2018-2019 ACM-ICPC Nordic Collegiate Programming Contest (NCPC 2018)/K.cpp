#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll dp[3005],n,k,ans=0;
vector<int> e[3005];

ll dfs(int now,int fa,ll k)
{
    ll tmp=1;
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs(to,now,k);
        tmp=tmp*dp[to]%mod;
    }
    dp[now]=(k-1)*tmp%mod;
    if(now==fa) return k*tmp%mod;
    return 0;
}

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

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1,x;i<n;i++)
        scanf("%d",&x),e[x].push_back(i),e[i].push_back(x);
    ll c=1;
    for(int i=k,j=0;i;i--,j++)
    {
        if(j&1) ans-=c*dfs(0,0,i)%mod;
        else ans+=c*dfs(0,0,i)%mod;
        ans=(ans+mod)%mod;
        c=c*i%mod*fp(k-i+1,mod-2)%mod;
    }
    printf("%lld",ans);
    return 0;
}

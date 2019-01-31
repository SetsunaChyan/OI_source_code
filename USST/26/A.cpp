#include <cstdio>
#include <memory.h>

typedef long long ll;

const int mod=1e9+7;
int n,m,k;
ll dp[1005],v[1005],vis[1005];

void f()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        for(int j=m;j>=v[i];j--)
            dp[j]=(dp[j]+dp[j-v[i]])%mod;
    }
    ll ans=0;
    for(int i=0;i<=m;i++)
        ans=(ans+dp[i])%mod;
    printf("%lld\n",ans);
}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    f();
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        vis[x-1]=1;
        f();
    }
    return 0;
}
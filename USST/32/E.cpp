#include <cstdio>
#include <memory.h>
#include <cmath>

typedef long long ll;
ll dp[20][100],n;
int l,a[20];

ll dfs(int p,int pre,bool limit)
{
    if(p==-1) return 1;
    if(~dp[p][pre]&&!limit) return dp[p][pre];
    ll ret=0;
    int n=limit?a[p]:9;
    for(int i=0;i<=n;i++)
    {
        if(pre==52&&i==0) continue;
        ret+=dfs(p-1,pre%10*10+i,limit&&i==a[p]);
    }
    if(!limit) dp[p][pre]=ret;
    return ret;
}

ll solve(ll x)
{
    int k=0;
    memset(dp,-1,sizeof(dp));
    while(x)
    {
        a[k++]=x%10;
        x/=10;
    }
    return dfs(k-1,0,true);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld",&n);
        printf("%lld\n",n-solve(n)+1);
    }
    return 0;
}
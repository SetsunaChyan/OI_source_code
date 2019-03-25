#include <cstdio>
#include <memory.h>

typedef long long ll;
ll dp[20][10],n,m;
int a[20];

inline int abs(int x){return x<0?-x:x;}

ll dfs(int p,int pre,bool limit,bool iszero)
{
    if(p==-1) return 1;
    if(~dp[p][pre]&&!limit&&!iszero) return dp[p][pre];
    ll ret=0;
    int n=limit?a[p]:9;
    for(int i=0;i<=n;i++)
    {
        if(iszero&&i==0)
        {
            ret+=dfs(p-1,0,false,true);
            continue;
        }
        if(!iszero&&abs(i-pre)<2) continue;
        ret+=dfs(p-1,i,limit&&i==a[p],false);
    }
    if(!limit&&!iszero) dp[p][pre]=ret;
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
    dfs(k-1,0,true,true);
}

int main()
{
    scanf("%lld%lld",&n,&m);
    printf("%lld",solve(m)-solve(n-1));
    return 0;
}
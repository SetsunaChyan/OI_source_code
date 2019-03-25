#include <cstdio>
#include <memory.h>

int n,m,dp[10][10],a[10];

int dfs(int p,int pre,bool limit)
{
    if(p==-1) return 1;
    if(~dp[p][pre]&&!limit) return dp[p][pre];
    int ret=0,n=limit?a[p]:9;
    for(int i=0;i<=n;i++)
    {
        if(i==4||pre==6&&i==2) continue;
        ret+=dfs(p-1,i,limit&&i==a[p]);
    }
    if(!limit) dp[p][pre]=ret;
    return ret;
}

int solve(int x)
{
    int k=0;
    memset(dp,-1,sizeof(dp));
    while(x)
    {
        a[k++]=x%10;
        x/=10;
    }
    return dfs(k-1,-1,true);
}

int main()
{
    while(~scanf("%d%d",&n,&m)&n&&m)
        printf("%d\n",solve(m)-solve(n-1));
    return 0;
}
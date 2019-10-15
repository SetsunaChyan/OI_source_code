#include <bits/stdc++.h>
using namespace std;
#define float double

int n,vis[1<<18];
float dp[1<<18],a[18][18];

float dfs(int now)
{
    if(vis[now]) return dp[now];
    vis[now]=1;
    dp[now]=0;
    float pp,p;
    int tmp,k;
    for(int i=0;i<n;i++)
    {
        if(((1<<i)&now)!=0) continue;
        tmp=(1<<i)|now;
        k=__builtin_popcount(tmp);
        k=k*(k-1)/2;
        pp=0;
        if(vis[tmp]) p=dp[tmp]; else p=dfs(tmp);
        for(int j=0;j<n;j++)
            if((1<<j)&now)
                pp+=a[j][i];
        dp[now]+=p*pp/k;
    }
    return dp[now];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&a[i][j]);
    vis[(1<<n)-1]=dp[(1<<n)-1]=1;
    for(int i=0;i<n;i++)
        printf("%.6f ",dfs(1<<i));
    return 0;
}

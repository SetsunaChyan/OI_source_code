#include <cstdio>
#include <memory.h>

const int INF=0x3f3f3f3f;
int n,a,b,d[205],dp[205];

void dfs(int now,int step)
{
    if(step<dp[now])
    {
        dp[now]=step;
        if(now+d[now]>=0&&now+d[now]<n)
            dfs(now+d[now],step+1);
        if(now-d[now]>=0&&now-d[now]<n)
            dfs(now-d[now],step+1);
    }
}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
        scanf("%d",&d[i]);
    dfs(a-1,0);
    if(dp[b-1]==INF)
        printf("-1");
    else
        printf("%d",dp[b-1]);
    return 0;
}
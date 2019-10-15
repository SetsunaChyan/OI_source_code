#include <bits/stdc++.h>
using namespace std;

double dp[120],ans;
int pos[6],tmppos[6],vis[120];

double check()
{
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<5;i++) vis[tmppos[i]]=1;
    dp[1]=1;
    for(int i=1;i<100;i++)
        for(int j=1;j<=6;j++)
        {
            if(vis[i+j]) continue;
            dp[min(100,i+j)]+=dp[i]/6;
        }
    return dp[100];
}

void dfs(int now,int cnt)
{
    if(cnt==5)
    {
        double qaq=check();
        if(qaq>ans)
        {
            for(int i=0;i<5;i++) pos[i]=tmppos[i];
            ans=qaq;
        }
        return;
    }
    for(int i=now+1;i<100;i++)
        tmppos[cnt]=i,dfs(i,cnt+1);
}

int main()
{
    dfs(1,0);
    printf("%.10f\n",ans);
    for(int i=0;i<5;i++) printf("%d ",pos[i]);
    return 0;
}

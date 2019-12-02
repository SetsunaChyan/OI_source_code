#include <bits/stdc++.h>
using namespace std;

int dp[205][205],n,k,ans,a[205];
vector<int> e[205];

void dfs(int now,int fa)
{
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs(to,now);
        dp[now][0]+=dp[to][k];
    }
    dp[now][0]+=a[now];
    for(int i=1;i<=k;i++)
    {
        int tmp=0;
        for(auto to:e[now])
        {
            if(to==fa) continue;
            if(k-i>=i) tmp+=dp[to][k-i];
            else tmp+=dp[to][i];
        }
        if(k-i>=i)
        {
            for(auto to:e[now])
            {
                if(to==fa) continue;
                dp[now][i]=max(dp[now][i],tmp-dp[to][k-i]+dp[to][i]);
            }
        }
        else dp[now][i]=tmp;
    }
    printf("now %d: \n",now);
    for(int i=0;i<=k;i++) printf("%d ",dp[now][i]);
    printf("\n");
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
    //for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            for(int g=0;g<=k;g++)
                dp[j][g]=0;
        printf("\n");
        dfs(1,1);
        for(int j=1;j<=n;j++)
            for(int g=0;g<=k;g++)
                ans=max(dp[j][k],ans);
    }
    printf("%d",ans);
    return 0;
}

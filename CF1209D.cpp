#include <bits/stdc++.h>
using namespace std;

int n,k,vis[100005],cntn,cntm,ans;
vector<int> e[100005];

void dfs(int now)
{
    cntn++;
    vis[now]=1;
    for(int i=0;i<e[now].size();i++)
    {
        int to=e[now][i];
        if(to==-1) continue;
        cntm++;
        if(vis[to]) continue;
        e[now][i]=-1;
        dfs(to);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0,u,v;i<k;i++)
        scanf("%d%d",&u,&v),
        e[u].push_back(v),
        e[v].push_back(u);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        cntn=cntm=0;
        dfs(i);
        ans+=cntm/2-cntn+1;
    }
    printf("%d",ans);
    return 0;
}

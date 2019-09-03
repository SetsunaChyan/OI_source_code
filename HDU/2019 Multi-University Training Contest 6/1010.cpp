#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
vector<int>g[2002];
int n,m;
ll w[2002],ans;
map<ll,ll> dfs(int u,int fa)
{
    vector<map<ll,ll>>ws;//每个map<积，方案>是一棵子树必包含根的所有方案
    for(auto &v:g[u])
        if(v!=fa)
            ws.push_back(dfs(v,u));//每个子树的方案整回来
    map<ll,ll>dp[2];
    //dp[0][1]=0;
    dp[0][w[u]]=1;//只选根的情况
    dp[0][w[u]]%=mod;
    int id=0;
    for(auto &ww:ws)//每个子树
    {
        dp[1-id].clear();
        for(auto &v:dp[id])
            dp[1-id][v.first]=v.second;
        for(auto &p:ww)//子树里的每种方案
        {
            for(auto &v:dp[id])
                if(v.first*p.first<=m)
                    dp[1-id][v.first*p.first]+=v.second,dp[1-id][v.first*p.first]%=mod;
        }
        /*printf("ri\n");
        for(auto &p:dp[1-id])
            printf("%lld %lld\n",p.first,p.second);*/
        id=1-id;
    }

    for(auto &p:dp[id])//塞答案里
        ans=(ans+p.second)%mod;
    /*
    printf("----\n%d %d\n",u,fa);
    for(auto &ww:ws)
    {
        puts("start");
        for(auto &p:ww)
            printf("%lld %lld\n",p.first,p.second);
    }
    puts("~");
    for(auto &p:dp[id])
        printf("%lld %lld\n",p.first,p.second);
    printf("ans:%lld\n",ans);*/
    return dp[id];
}

int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%lld",w+i),g[i].clear();
        for(int i=1,u,v;i<n;i++)
            scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
        dfs(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}

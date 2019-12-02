#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,x,y,col,vis[25005],st,deg[25005],cnt[25005];
ll dis[25005];
vector<pii> e[25005],ee[25005];
vector<int> p[25005],out[25005];
queue<int> qq;

void dfs(int now)
{
    p[col].push_back(now);
    vis[now]=col;
    for(auto to:e[now])
        if(!vis[to.first]) dfs(to.first);
}

void dij(int c)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for(auto i:p[c])
        if(dis[i]<inf) q.emplace(dis[i],i);
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(cnt[now]) continue;
        cnt[now]=1;
        for(auto to:e[now])
            if(dis[now]+to.second<dis[to.first])
            {
                dis[to.first]=dis[now]+to.second;
                q.emplace(dis[to.first],to.first);
            }
        for(auto to:ee[now])
            if(dis[now]+to.second<dis[to.first])
                dis[to.first]=dis[now]+to.second;
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&x,&y,&st);
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    for(int i=0,u,v,w;i<x;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) col++,dfs(i);
    for(int i=0,u,v,w;i<y;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        ee[u].emplace_back(v,w);
        out[vis[u]].push_back(vis[v]);
        deg[vis[v]]++;
    }
    for(int i=1;i<=col;i++)
        if(!deg[i]) qq.push(i);
    while(!qq.empty())
    {
        int now=qq.front();qq.pop();
        dij(now);
        for(auto to:out[now])
        {
            deg[to]--;
            if(!deg[to]) qq.push(to);
        }
    }
    for(int i=1;i<=n;i++)
        if(dis[i]>=inf) printf("NO PATH\n");
        else printf("%lld\n",dis[i]);
    return 0;
}

/*
11 9 6 6
1 2 4
1 3 5
2 3 6
4 5 1
4 6 2
5 6 8
7 8 200
8 9 400
7 9 300
2 4 -10
3 5 -10
5 10 -20
4 7 -20
6 8 -50
11 10 -100

*/

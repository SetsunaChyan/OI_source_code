#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,vis[400];
ll dis[400];
vector<int> e[400];
vector<ll> val[400];

void SPFA(int st)
{
    for(int i=0;i<n;i++)
        dis[i]=0x3f3f3f3f3f3f3f3fll,vis[i]=0;
    dis[st]=0;
    queue<int> q;
    q.push(st);
    vis[st]=1;
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=0;i<e[now].size();i++)
        {
            int y=e[now][i],v=val[now][i];
            if(dis[now]+v<dis[y])
            {
                dis[y]=dis[now]+v;
                if(!vis[y]) vis[y]=1,q.push(y);
            }
        }
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        e[i].clear();
        val[i].clear();
    }
    for(int i=0,u,v,w;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(v);
        val[u].push_back(w);
    }
    for(int i=0,s,t;i<6;i++)
    {
        scanf("%d%d",&s,&t);
        SPFA(t);
        printf("%lld\n",-dis[s]);
        e[s].push_back(t);
        val[s].push_back(-dis[s]);
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

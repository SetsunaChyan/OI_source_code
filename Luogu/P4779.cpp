#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

int n,m,vis[100005],st;
ll dis[100005];
vector<ll> e[100005],v[100005];
priority_queue<pli,vector<pli>,greater<pli> > q;

void dij(int st)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    q.emplace(0ll,st);
    while(!q.empty())
    {
        pli p=q.top();
        q.pop();
        int now=p.second;
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=0;i<e[now].size();i++)
        {
            int to=e[now][i];ll val=v[now][i];
            if(val+p.first<dis[to])
            {
                dis[to]=val+p.first;
                q.emplace(dis[to],to);
            }
        }
    }
}

void solve()
{
    scanf("%d%d%d",&n,&m,&st);
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++)
    {
        e[i].clear();
        v[i].clear();
    }
    for(int i=0;i<m;i++)
    {
        int x,y;ll z;
        scanf("%d%d%lld",&x,&y,&z);
        e[x].push_back(y),v[x].push_back(z);
    }
    dij(st);
    for(int i=1;i<=n;i++)
        printf("%lld ",dis[i]);
}

int main()
{
    int _=1;
    //scanf("%d",&_);
    while(_--) solve();
    return 0;
}


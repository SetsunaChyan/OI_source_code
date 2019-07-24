#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<ll,ll>
#define mp make_pair
typedef long long ll;

struct Edge
{
    ll v,cap,flow,next;
}e[20020];
vector<ll> g[10010];
vector<ll> ee[100005],ev[100005];
ll first[10010],dis[10010],cur[10010],tot,N;
bool vis[10010];

void add(ll u,ll v,ll cap)
{
    e[tot]=Edge{v,cap,0,first[u]};
    first[u]=tot++;
}

void dij()
{
    priority_queue<pii,vector<pii>,greater<pii> > q;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    q.emplace(0ll,1);
    while(!q.empty())
    {
        pii p=q.top();
        q.pop();
        int now=p.second;
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=0;i<ee[now].size();i++)
        {
            ll to=ee[now][i],val=ev[now][i];
            if(val+p.first<dis[to])
            {
                dis[to]=val+p.first;
                q.emplace(dis[to],to);
            }
        }
    }
}

bool bfs()
{
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(1);
    dis[1]=0;
    vis[1]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=first[u];~i;i=e[i].next)
        if(!vis[e[i].v]&&e[i].cap-e[i].flow>0)
        {
            vis[e[i].v]=1;
            dis[e[i].v]=dis[u]+1;
            q.push(e[i].v);
        }
    }
    return vis[N];
}

ll dfs(ll u,ll a)
{
    if(u==N||a==0) return a;
    ll f,ans=0;
    for(int i=cur[u];~i;i=e[i].next)
        if(dis[e[i].v]==dis[u]+1&&(f=dfs(e[i].v,min(a,e[i].cap-e[i].flow)))>0)
        {
            e[i].flow+=f;
            e[i^1].flow-=f;
            a-=f;
            ans+=f;
            if(!a) break;
        }
    return ans;
}

void solve()
{
    ll ans=0;
    while(bfs())
    {
        for(int i=1;i<=N;++i) cur[i]=first[i];
        ans+=dfs(1,inf);
    }
    printf("%lld\n",ans);
}

int main()
{
    int M,_,i,j,k;
    ll u[10100],v[10100],w[10100];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&N,&M);
        memset(first,-1,sizeof(first));
        tot=0;
        for(i=1;i<=N;++i) g[i].clear(),ee[i].clear(),ev[i].clear();
        for(i=1;i<=M;++i)
        {
            int x,y;ll z;
            scanf("%d%d%lld",&x,&y,&z);
            ee[x].push_back(y),ev[x].push_back(z);
        }
        dij();
        for(i=1;i<=N;++i)
            for(int j=0;j<ee[i].size();j++)
            {
                ll to=ee[i][j],val=ev[i][j];
                if(dis[i]+val==dis[to])
                    add(i,to,val),add(to,i,0);
            }
        solve();
    }
    return 0;
}

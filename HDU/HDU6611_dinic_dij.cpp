#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int MAXN=2005;
const int inf=0x3f3f3f3f;
int tot,ans,s,t,n,k,a[MAXN],cur[2*MAXN],dis[2*MAXN],vis[2*MAXN],h[2*MAXN];
struct edge
{
    int to,val,cap,rev;
    edge(){}
    edge(int to,int cap,int val,int rev):to(to),cap(cap),val(val),rev(rev){}
};
vector<edge> E[2*MAXN];

inline void add_edge(int x,int y,int f,int cost)
{
    E[x].emplace_back(y,f,cost,E[y].size());
    E[y].emplace_back(x,0,-cost,E[x].size()-1);
}

int dij()
{
    fill(dis,dis+t+1,inf);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.emplace(0,s);dis[s]=0;
    while(!q.empty())
    {
        pii p=q.top();q.pop();
        int now=p.second;
        if(dis[now]<p.first) continue;
        for(int i=0;i<E[now].size();i++)
        {
            edge &e=E[now][i];
            if(e.cap>0&&dis[e.to]>p.first+e.val+h[now]-h[e.to])
            {
                dis[e.to]=p.first+e.val+h[now]-h[e.to];
                q.emplace(dis[e.to],e.to);
            }
        }
    }
    return dis[t]!=inf;
}

int dfs(int now,int flow)
{
    if(now==t) return flow;
    int rest=flow,k;
    vis[now]=1;
    for(int i=cur[now];i<E[now].size();i++)
    {
        edge &e=E[now][i];
        if(e.cap&&dis[now]+e.val+h[now]-h[e.to]==dis[e.to]&&!vis[e.to])
        {
            cur[now]=i;
            k=dfs(e.to,min(e.cap,rest));
            e.cap-=k;
            E[e.to][e.rev].cap+=k;
            rest-=k;
            ans+=k*e.val;
        }
    }
    vis[now]=0;
    return flow-rest;
}

int dinic()
{
    int ret=0,delta;
    while(dij())
    {
        for(int i=s;i<=t;i++) cur[i]=0;
        while(delta=dfs(s,inf)) ret+=delta;
        for(int i=s;i<=t;i++) h[i]+=(dis[i]==inf)?0:dis[i];
    }
    return ret;
}

void solve()
{
    scanf("%d%d",&n,&k);
    s=0,t=2+2*n+1;
    tot=ans=0;
    memset(h,0,sizeof(h));
    for(int i=s;i<=t;i++) E[i].clear();
    add_edge(0,1,k,0);
    for(int i=1;i<=n;i++) scanf("%d",a+i),add_edge(i+1,i+n+1,1,-a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[j]>=a[i]) add_edge(i+n+1,j+1,1,0);
    for(int i=1;i<=n;i++)
        add_edge(1,i+1,1,0),add_edge(i+n+1,t,1,0);
    dinic();
    printf("%d\n",-ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

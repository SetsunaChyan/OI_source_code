#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=0x3f3f3f3f3f3f3f3fll;
ll mincost,dis[5005];
int s,t,n,m,head[5005],tot=0,cur[5005],vis[5005];
struct edge
{
    int to,nxt;
    ll cap,cost;
}e[50005<<2];

void add_edge(int x,int y,int cap,int cost)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=cap,e[tot].cost=cost,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,e[tot].cost=-cost,head[y]=tot++;
}

int spfa()
{
    for(int i=1;i<=n;i++) vis[i]=0,dis[i]=inf;
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int p=q.front();q.pop();
        vis[p]=0;
        for(int i=head[p];~i;i=e[i].nxt)
            if(e[i].cap&&dis[p]+e[i].cost<dis[e[i].to])
            {
                dis[e[i].to]=dis[p]+e[i].cost;
                if(!vis[e[i].to])
                    vis[e[i].to]=1,q.push(e[i].to);
            }
    }
    return dis[t]!=inf;
}

ll dfs(int now,ll flow)
{
    if(now==t) return flow;
    ll rest=flow,k;
    vis[now]=1;
    for(int i=cur[now];~i;i=e[i].nxt)
        if(e[i].cap&&dis[now]+e[i].cost==dis[e[i].to]&&!vis[e[i].to])
        {
            cur[now]=i;
            k=dfs(e[i].to,min(rest,e[i].cap));
            e[i].cap-=k;
            e[i^1].cap+=k;
            mincost+=k*e[i].cost;
            rest-=k;
        }
    vis[now]=0;
    return flow-rest;
}

ll dinic()
{
    mincost=0;
    ll ret=0,delta;
    while(spfa())
    {
        for(int i=1;i<=n;i++) cur[i]=head[i];
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++)
    {
        int x,y,a,b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        add_edge(x,y,a,b);
    }
    ll mxflow=dinic();
    printf("%lld %lld",mxflow,mincost);
    return 0;
}

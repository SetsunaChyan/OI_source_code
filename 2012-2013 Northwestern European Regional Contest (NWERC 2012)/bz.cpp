#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define int long long
/*
    第一遍跑的spfa,然后是加上势函数的dij,玄学
    h[] 势函数
    cur[] 当前弧优化
    msmf 最大流时的最小费用
    s,t 超级源、超级汇
    时间复杂度 O(n^2*m)
*/

const int inf=0x3f3f3f3f;
int s,t,n,m,head[5005],tot=0,cur[5005],vis[5005],dis[5005],mincost;
struct edge
{
    int to,nxt,cap,cost;
}e[50005<<2];

void add_edge(int x,int y,int cap,int cost)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=cap,e[tot].cost=cost,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,e[tot].cost=-cost,head[y]=tot++;
}

int spfa()
{
    for(int i=1;i<=2*n;i++) vis[i]=0,dis[i]=inf;
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

int dfs(int now,int flow)
{
    if(now==t) return flow;
    int rest=flow,k;
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

int dinic()
{
    mincost=0;
    int ret=0,delta;
    while(spfa())
    {
        for(int i=1;i<=2*n;i++) cur[i]=head[i],vis[i]=0;
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

signed main()
{
    scanf("%lld%lld%lld%d",&n,&m,&s,&t);
    for(int i=0,x,y,z,f;i<m;i++)
    {
        scanf("%lld%lld%d%d",&x,&y,&z,&f);
        add_edge(x,y,z,f);
    }
    int flow=dinic();
    printf("%lld %lld",flow,mincost);
    return 0;
}

/*
5 7
1 2 2
2 5 3
1 3 3
3 5 2
1 4 2
4 5 2
2 3 0
*/


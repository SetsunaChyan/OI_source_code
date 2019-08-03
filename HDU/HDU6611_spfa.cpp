#include <bits/stdc++.h>
using namespace std;

const int MAXN=2005;
const int inf=0x7fffffff;
int head[2*MAXN],tot,ans,s,t,n,k,a[MAXN],cur[2*MAXN],dis[2*MAXN],vis[2*MAXN];
struct edge
{
    int to,val,cap,nxt;
}e[MAXN*MAXN<<2];

void add_edge(int x,int y,int f,int cost)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=f,e[tot].val=cost,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,e[tot].val=-cost,head[y]=tot++;
}

int bfs()
{
    for(int i=s;i<=t;i++) dis[i]=inf,vis[i]=0;
    queue<int> q;
    dis[s]=0;q.push(s);
    while(!q.empty())
    {
        int p=q.front();q.pop();
        vis[p]=0;
        for(int i=head[p];~i;i=e[i].nxt)
            if(e[i].cap&&dis[p]+e[i].val<dis[e[i].to])
            {
                dis[e[i].to]=dis[p]+e[i].val;
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
    for(int i=cur[now];~i&&rest;i=e[i].nxt)
        if(e[i].cap&&dis[now]+e[i].val==dis[e[i].to]&&!vis[e[i].to])
        {
            cur[now]=i;
            k=dfs(e[i].to,min(e[i].cap,rest));
            e[i].cap-=k;
            e[i^1].cap+=k;
            rest-=k;
            ans+=k*e[i].val;
        }
    return flow-rest;
}

int dinic()
{
    int ret=0,delta;
    while(bfs())
    {
        printf("start dfs\n");
        for(int i=s;i<=t;i++) cur[i]=head[i],vis[i]=0;
        while(delta=dfs(s,inf)) ret+=delta;
        printf("end dfs\n");
    }
    return ret;
}

void solve()
{
    memset(head,-1,sizeof(head));
    tot=ans=0;
    scanf("%d%d",&n,&k);
    s=0,t=2+2*n+1;
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
    freopen("HDU6611data.in","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}


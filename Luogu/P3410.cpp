#include <bits/stdc++.h>
using namespace std;

const int MAXN=205;
const int inf=0x3f3f3f3f;
int n,m,head[MAXN],cur[MAXN],tot=0,dis[MAXN],ans=0;
struct edge
{
    int to,nxt,cap;
}e[MAXN*MAXN<<2];

void add_edge(int x,int y,int z)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=z,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,head[y]=tot++;
}

int bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(0);
    dis[0]=0;
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=head[p];~i;i=e[i].nxt)
            if(e[i].cap&&dis[p]+1<dis[e[i].to])
            {
                dis[e[i].to]=dis[p]+1;
                if(e[i].to==n+m+1) return 1;
                q.push(e[i].to);
            }
    }
    return 0;
}

int dfs(int now,int flow)
{
    if(now==n+m+1) return flow;
    int rest=flow,k;
    for(int i=cur[now];~i;i=e[i].nxt)
        if(e[i].cap&&dis[e[i].to]==dis[now]+1)
        {
            cur[now]=i;
            k=dfs(e[i].to,min(rest,e[i].cap));
            e[i].cap-=k;
            e[i^1].cap+=k;
            rest-=k;
        }
    return flow-rest;
}

int dinic()
{
    int ret=0,delta;
    while(bfs())
    {
        for(int i=0;i<=n+m+1;i++) cur[i]=head[i];
        while(delta=dfs(0,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d",&z);
        ans+=z;
        add_edge(0,n+i,z);
        while(scanf("%d",&x)&&x) add_edge(n+i,x,inf);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add_edge(i,n+m+1,x);
    }
    printf("%d",ans-dinic());
    return 0;
}

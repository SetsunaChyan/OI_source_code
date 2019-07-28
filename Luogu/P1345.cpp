#include <bits/stdc++.h>
using namespace std;

const int MAXN=205;
const int inf=0x3f3f3f3f;
int n,m,s,t,head[MAXN],cur[MAXN],dis[MAXN],tot;
struct edge
{
    int to,nxt,cap;
}e[4005];

void add_edge(int x,int y,int z)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=z,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,head[y]=tot++;
}

int bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(s),dis[s]=0;
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=head[p];~i;i=e[i].nxt)
            if(e[i].cap&&dis[p]+1<dis[e[i].to])
            {
                dis[e[i].to]=dis[p]+1;
                if(e[i].to==t) return 1;
                q.push(e[i].to);
            }
    }
    return 0;
}

int dfs(int now,int flow)
{
    if(now==t) return flow;
    int rest=flow,k;
    for(int i=cur[now];~i;i=e[i].nxt)
        if(e[i].cap&&dis[now]+1==dis[e[i].to])
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
        for(int i=0;i<=2*n;i++) cur[i]=head[i];
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;i++)
        add_edge(i,n+i,1);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x+n,y,inf);
        add_edge(y+n,x,inf);
    }
    s+=n;
    printf("%d",dinic());
    return 0;
}

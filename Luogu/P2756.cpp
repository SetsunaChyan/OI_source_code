#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;
const int inf=0x3f3f3f3f;
int head[MAXN],cur[MAXN],dis[MAXN],n,m,tot=0,x,y;
struct edge
{
    int to,cap,nxt;
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
    q.push(0);dis[0]=0;
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=head[p];~i;i=e[i].nxt)
            if(e[i].cap&&dis[p]+1<dis[e[i].to])
            {
                dis[e[i].to]=dis[p]+1;
                if(e[i].to==n+1) return 1;
                q.push(e[i].to);
            }
    }
    return 0;
}

int dfs(int now,int flow)
{
    if(now==n+1) return flow;
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
        for(int i=0;i<=n+1;i++) cur[i]=head[i];
        while(delta=dfs(0,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++) add_edge(0,i,1);
    for(int i=m+1;i<=n;i++) add_edge(i,n+1,1);
    while(~scanf("%d%d",&x,&y)&&x!=-1&&y!=-1)
        add_edge(x,y,1);
    int ans=dinic();
    if(ans==0)
    {
        printf("No Solution!");
        return 0;
    }
    printf("%d\n",ans);
    for(int i=1;i<=m;i++)
        for(int j=head[i];~j;j=e[j].nxt)
            if(e[j].to!=0&&e[j].cap==0)
                printf("%d %d\n",i,e[j].to);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
int a,b,c,q,s,t,head[40005],cur[40005],dis[40005],tot;
struct edge
{
    int to,nxt,cap;
}e[200005];

void add_edge(int x,int y,int z)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=z,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,head[y]=tot++;
}

int bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(s);dis[s]=0;
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=head[p];~i;i=e[i].nxt)
            if(e[i].cap&&dis[e[i].to]>dis[p]+1)
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
        for(int i=s;i<=t;i++) cur[i]=head[i];
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&a,&b,&c,&q);
    s=0,t=b+2*a+c+1;
    for(int i=1;i<=a;i++) add_edge(i,a+b+c+i,1);
    for(int i=a+1;i<=a+b;i++) add_edge(s,i,1);
    for(int i=a+b+1;i<=a+b+c;i++) add_edge(i,t,1);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(a+y,x,1);
    }
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(a+b+c+x,a+b+y,1);
    }
    printf("%d",dinic());
    return 0;
}

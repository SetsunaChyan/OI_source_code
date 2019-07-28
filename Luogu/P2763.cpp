#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
int n,k,s,t,head[2005],tot,cur[2005],dis[2005],sum;
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
    dis[s]=0;q.push(s);
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=head[p];~i;i=e[i].nxt)
            if(e[i].cap&&dis[e[i].to]>1+dis[p])
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
    scanf("%d%d",&k,&n);
    s=0,t=n+k+1;
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        add_edge(s,n+i,x);
    }
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        add_edge(i,t,1);
        for(int j=1;j<=num;j++)
        {
            int x;
            scanf("%d",&x);
            add_edge(x+n,i,1);
        }
    }
    int ans=dinic();
    if(ans!=sum)
    {
        printf("No Solution!");
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        printf("%d:",i);
        for(int j=head[i+n];~j;j=e[j].nxt)
            if(e[j].cap==0&&e[j].to>=1&&e[j].to<=n)
                printf(" %d",e[j].to);
        printf("\n");
    }
    return 0;
}

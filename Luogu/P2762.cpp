#include <bits/stdc++.h>
using namespace std;

const int MAXN=205;
const int inf=0x3f3f3f3f;
int n,m,s,t,head[MAXN],cur[MAXN],dis[MAXN],ans=0,tot=0;
vector<int> a,b;
char tools[10000];
struct edge
{
    int to,nxt,cap;
}e[MAXN*MAXN<<1];

void add_edge(int x,int y,int z)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=z,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,head[y]=tot++;
}

int bfs(int op)
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    dis[s]=0,q.push(s);
    while(!q.empty())
    {
        int p=q.front();q.pop();
        if(op)
        {
            if(p>n) a.push_back(p-n);
            else if(p!=s) b.push_back(p);
        }
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
    while(bfs(0))
    {
        for(int i=s;i<=t;i++) cur[i]=head[i];
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&m,&n);
    s=0,t=m+n+1;
    for(int i=1;i<=m;i++)
    {
        int ulen=0,tool,x;
        memset(tools,0,sizeof tools);
        scanf("%d",&x);
        add_edge(s,n+i,x);ans+=x;
        cin.getline(tools,10000);
        while(sscanf(tools+ulen,"%d",&tool)==1)
        {
            add_edge(n+i,tool,inf);
            if(tool==0) ulen++;
            else while(tool) tool/=10,ulen++;
            ulen++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add_edge(i,t,x);
    }
    int cut=dinic();
    bfs(1);
    for(auto i:a) printf("%d ",i);
    printf("\n");
    for(auto i:b) printf("%d ",i);
    printf("\n%d",ans-cut);
    return 0;
}

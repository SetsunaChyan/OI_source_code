#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=105*105;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m,head[MAXN],s,t,cur[MAXN],dis[MAXN],tot=0;
ll a[105][105],ans=0;
struct edge
{
    int to,nxt;
    ll cap;
}e[MAXN<<3];

void add_edge(int x,int y,ll z)
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
            if(e[i].cap&&dis[p]+1<dis[e[i].to])
            {
                dis[e[i].to]=dis[p]+1;
                if(e[i].to==t) return 1;
                q.push(e[i].to);
            }
    }
    return 0;
}

ll dfs(int now,ll flow)
{
    if(now==t) return flow;
    ll rest=flow,k;
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
    ll ret=0,delta;
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
    scanf("%d%d",&n,&m);
    s=0,t=n*m+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%lld",&a[i][j]),ans+=a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if((i+j)&1)
            {
                add_edge(i*m+j+1,t,a[i][j]);
                continue;
            }
            else
                add_edge(s,i*m+j+1,a[i][j]);
            if(i) add_edge(i*m+j+1,(i-1)*m+j+1,inf);
            if(j) add_edge(i*m+j+1,i*m+j,inf);
            if(i!=n-1) add_edge(i*m+j+1,(i+1)*m+j+1,inf);
            if(j!=m-1) add_edge(i*m+j+1,i*m+j+2,inf);
        }
    printf("%lld",ans-dinic());
    return 0;
}

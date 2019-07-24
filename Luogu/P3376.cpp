#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m,s,t,head[10005],tot=0,dep[10005],cur[10005];
struct edge
{
    int to,nxt;
    ll cap;
}e[400005];

void add_edge(int x,int y,int z)
{
    e[tot].to=y;
    e[tot].nxt=head[x];
    e[tot].cap=z;
    head[x]=tot++;
}

int bfs()
{
    for(int i=1;i<=n;i++) dep[i]=0x3f3f3f3f;
    dep[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=head[p];~i;i=e[i].nxt)
            if(dep[e[i].to]>dep[p]+1&&e[i].cap)
            {
                dep[e[i].to]=dep[p]+1;
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
        if(e[i].cap&&dep[e[i].to]==dep[now]+1)
        {
            cur[now]=i;
            k=dfs(e[i].to,min(rest,e[i].cap));
            e[i].cap-=k;
            e[i^1].cap+=k;
            rest-=k;
        }
    return flow-rest;
}

ll dinic()
{
    ll ret=0,delta;
    while(bfs())
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
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        add_edge(x,y,c);
        add_edge(y,x,0);
    }
    printf("%lld",dinic());
    return 0;
}

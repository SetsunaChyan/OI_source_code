#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
int mat[200][200],n,m,s,t,ans,cur[500],dis[500],in[200],out[200];
struct edge
{
    int to,cap,rev;
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};
vector<edge> e[500];

void add_edge(int x,int y,int z)
{
    e[x].emplace_back(y,z,e[y].size());
    e[y].emplace_back(x,0,e[x].size()-1);
}

int bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(s),dis[s]=0;
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=0;i<e[p].size();i++)
        {
            int to=e[p][i].to;
            if(e[p][i].cap&&dis[to]>dis[p]+1)
            {
                dis[to]=dis[p]+1;
                if(to==t) return 1;
                q.push(to);
            }
        }
    }
    return 0;
}

int dfs(int now,int flow)
{
    if(now==t) return flow;
    int rest=flow,k;
    for(int i=cur[now];i<e[now].size();i++)
    {
        int to=e[now][i].to;
        if(e[now][i].cap&&dis[to]==dis[now]+1)
        {
            cur[now]=i;
            k=dfs(to,min(rest,e[now][i].cap));
            e[now][i].cap-=k;
            e[to][e[now][i].rev].cap+=k;
            rest-=k;
        }
    }
    return flow-rest;
}

int dinic()
{
    int ret=0,delta;
    while(bfs())
    {
        memset(cur,0,sizeof(cur));
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    s=0,t=2*n+1,ans=n;
    for(int i=1;i<=n;i++)
    {
        add_edge(s,i,1);
        add_edge(i+n,t,1);
    }
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v+n,1);
    }
    ans-=dinic();
    for(int i=1;i<=n;i++)
        for(int j=0;j<e[i].size();j++)
            if(e[i][j].to!=s&&e[i][j].cap==0)
            {
                in[e[i][j].to-n]=i;
                out[i]=e[i][j].to-n;
            }
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            for(int j=i;j;j=out[j]) printf("%d%c",j," \n"[out[j]==0]);
    printf("%d",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int MAXN=200005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll inff=0x3f3f3f3f3f3fll;
const int mv[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,s,t,k,dis[MAXN],cur[MAXN];
ll cost[MAXN];
char mp[35][35];
struct edge
{
    int to,rev;
    ll cap;
    edge(){}
    edge(int to,ll cap,int rev):to(to),cap(cap),rev(rev){}
};
vector<edge> E[MAXN];

inline void add_edge(int x,int y,ll f)
{
    E[x].emplace_back(y,f,E[y].size());
    E[y].emplace_back(x,0,E[x].size()-1);
}

int bfs()
{
    for(int i=s;i<=t;i++) dis[i]=0x3f3f3f3f;
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=0;i<E[now].size();i++)
        {
            edge &e=E[now][i];
            if(dis[e.to]>dis[now]+1&&e.cap)
            {
                dis[e.to]=dis[now]+1;
                if(e.to==t) return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

ll dfs(int now,ll flow)
{
    if(now==t) return flow;
    ll rest=flow,k;
    for(int i=cur[now];i<E[now].size();i++)
    {
        edge &e=E[now][i];
        if(e.cap&&dis[e.to]==dis[now]+1)
        {
            cur[now]=i;
            k=dfs(e.to,min(rest,e.cap));
            e.cap-=k;
            E[e.to][e.rev].cap+=k;
            rest-=k;
        }
    }
    return flow-rest;
}

ll dinic()
{
    ll ret=0,delta;
    while(bfs())
    {
        for(int i=s;i<=t;i++) cur[i]=0;
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

signed main()
{
    scanf("%lld%lld%lld",&m,&n,&k);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<k;i++) scanf("%lld",&cost[i]);
    s=0,t=2*n*m+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='.')
                add_edge(i*m+j+1,n*m+(i*m+j+1),inff);
            else if(mp[i][j]!='B')
                add_edge(i*m+j+1,n*m+(i*m+j+1),cost[mp[i][j]-'a']);
            for(int dir=0;dir<4;dir++)
            {
                int dx=i+mv[dir][0],dy=j+mv[dir][1];
                if(mp[i][j]=='B')
                {
                    if(dx==-1||dx==n||dy==-1||dy==m)
                    {
                        printf("-1");
                        return 0;
                    }
                    continue;
                }
                if(dx==-1||dx==n||dy==-1||dy==m)
                    add_edge(n*m+(i*m+j+1),t,inff);
                else if(mp[dx][dy]=='B')
                    add_edge(s,i*m+j+1,inff);
                else
                    add_edge(n*m+(i*m+j+1),dx*m+dy+1,inff);
            }
        }
    ll ans=dinic();
    if(ans>=inff) printf("-1"); else printf("%lld",ans);
    return 0;
}
/*
3 3 1
.a.
aBa
.a.
1
*/

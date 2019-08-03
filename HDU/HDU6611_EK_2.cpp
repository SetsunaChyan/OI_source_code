#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int MAXN=2005;
const int inf=0x3f3f3f3f;
int head[2*MAXN],tot,ans,s,t,n,k,a[MAXN],cur[2*MAXN],dis[2*MAXN],vis[2*MAXN],h[2*MAXN],pree[2*MAXN],prever[2*MAXN];
struct edge
{
    int to,val,cap,rev;
    edge(){}
    edge(int to,int cap,int val,int rev):to(to),cap(cap),val(val),rev(rev){}
};
vector<edge> E[2*MAXN];

inline void add_edge(int x,int y,int f,int cost)
{
    E[x].emplace_back(y,f,cost,E[y].size());
    E[y].emplace_back(x,0,-cost,E[x].size()-1);
}

int dij()
{
    fill(dis,dis+t+1,inf);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.emplace(0,s);dis[s]=0;
    while(!q.empty())
    {
        pii p=q.top();q.pop();
        int now=p.second;
        if(dis[now]<p.first) continue;
        for(int i=0;i<E[now].size();i++)
        {
            edge &e=E[now][i];
            if(e.cap>0&&dis[e.to]>p.first+e.val+h[now]-h[e.to])
            {
                dis[e.to]=p.first+e.val+h[now]-h[e.to];
                pree[e.to]=i;
                prever[e.to]=now;
                q.emplace(dis[e.to],e.to);
            }
        }
    }
    return dis[t]!=inf;
}

int EK()
{
    int ret=0;
    int qaq=0;
    while(dij())
    {
        printf("%d\n",++qaq);
        for(int i=s;i<=t;i++) h[i]+=(dis[i]==inf)?0:dis[i];
        int flow=inf;
        for(int i=t;i!=s;i=prever[i]) flow=min(flow,E[prever[i]][pree[i]].cap);
        for(int i=t;i!=s;i=prever[i])
        {
            edge &e=E[prever[i]][pree[i]];
            e.cap-=flow,E[i][e.rev].cap+=flow;
        }
        ret+=flow;
        ans+=h[t]*flow;
    }
    return ret;
}

void solve()
{
    scanf("%d%d",&n,&k);
    tot=ans=0;
    s=0,t=2+2*n+1;
    fill(head,head+t+1,-1);
    fill(h,h+t+1,0);
    for(int i=s;i<=t;i++) E[i].clear();
    add_edge(0,1,k,0);
    for(int i=1;i<=n;i++) scanf("%d",a+i),add_edge(i+1,i+n+1,1,-a[i]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[j]>=a[i]) add_edge(i+n+1,j+1,1,0);
    for(int i=1;i<=n;i++)
        add_edge(1,i+1,1,0),add_edge(i+n+1,t,1,0);
    EK();
    printf("%d\n",-ans);
}

int main()
{
    freopen("HDU6611data.in","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

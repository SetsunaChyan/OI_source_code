#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int MAXN=2005;
const int inf=0x3f3f3f3f;
int head[2*MAXN],tot,ans,s,t,n,k,a[MAXN],cur[2*MAXN],dis[2*MAXN],vis[2*MAXN],h[2*MAXN],pree[2*MAXN],prever[2*MAXN];
struct edge
{
    int to,val,cap,nxt;
}e[MAXN*MAXN<<2];

inline void add_edge(int x,int y,int f,int cost)
{
    e[tot].to=y,e[tot].nxt=head[x],e[tot].cap=f,e[tot].val=cost,head[x]=tot++;
    e[tot].to=x,e[tot].nxt=head[y],e[tot].cap=0,e[tot].val=-cost,head[y]=tot++;
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
        for(int i=head[now];~i;i=e[i].nxt)
        {
            edge &ei=e[i];
            if(ei.cap>0&&dis[ei.to]>p.first+ei.val+h[now]-h[ei.to])
            {
                dis[ei.to]=p.first+ei.val+h[now]-h[ei.to];
                pree[ei.to]=i;
                prever[ei.to]=now;
                q.emplace(dis[ei.to],ei.to);
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
        for(int i=t;i!=s;i=prever[i]) flow=min(flow,e[pree[i]].cap);
        for(int i=t;i!=s;i=prever[i])
            e[pree[i]].cap-=flow,e[pree[i]^1].cap+=flow;
        ret+=flow;
        ans+=h[t]*flow;
    }
    return ret;
}

void solve()
{
    tot=ans=0;
    scanf("%d%d",&n,&k);
    s=0,t=2+2*n+1;
    fill(head,head+t+1,-1);
    fill(h,h+t+1,0);
    for(int i=1;i<=n;i++)
        for(int j=n;j>=i+1;j--)
            if(a[j]>=a[i]) add_edge(i+n+1,j+1,1,0);
    for(int i=1;i<=n;i++)
        add_edge(1,i+1,1,0),add_edge(i+n+1,t,1,0);
    for(int i=1;i<=n;i++) scanf("%d",a+i),add_edge(i+1,i+n+1,1,-a[i]);
    add_edge(0,1,k,0);
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

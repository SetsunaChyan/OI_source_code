#include <cstdio>
#include <memory.h>

typedef long long ll;
const int MAXN=2e5+5;
ll ans=0,res=0,sum[MAXN],v[MAXN];
int n,tot=0,head[MAXN];
struct edge
{
    int to,next;
}e[MAXN<<1];

inline ll max(ll a,ll b){return a>b?a:b;}

inline void addedge(int x,int y)
{
    e[tot].next=head[x];
    e[tot].to=y;
    head[x]=tot;
    tot++;
}

void dfs1(int now,int fa,int dep)
{
    res+=dep*v[now];
    sum[now]=v[now];
    for(int i=head[now];~i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs1(e[i].to,now,dep+1);
            sum[now]+=sum[e[i].to];
        }
}

void dfs2(int now,int fa)
{
    ans=max(ans,res);
    for(int i=head[now];~i;i=e[i].next)
        if(e[i].to!=fa)
        {
            res-=sum[e[i].to];
            sum[now]-=sum[e[i].to];
            res+=sum[now];
            sum[e[i].to]+=sum[now];
            dfs2(e[i].to,now);
            sum[e[i].to]-=sum[now];
            res-=sum[now];
            sum[now]+=sum[e[i].to];
            res+=sum[e[i].to];
        }
}

int main()
{
    memset(sum,0,sizeof(sum));
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs1(1,-1,0);
    dfs2(1,-1);
    printf("%lld",ans);
    return 0;
}
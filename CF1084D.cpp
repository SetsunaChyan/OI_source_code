#include <cstdio>
#include <memory.h>

typedef long long ll;
const int maxn=3e5+50;
int n,head[maxn],tot=0;
ll v[maxn],dp[maxn],bk[maxn],ans=0;
struct edge
{
    int to,next;
    ll val;
}e[maxn<<1];

inline ll max(ll a,ll b){return a>b?a:b;}
inline void addedge(int a,int b,ll z)
{
    e[tot].next=head[a];
    e[tot].to=b;
    e[tot].val=z;
    head[a]=tot;
    tot++;
}

void dfs(int now,int fa,ll cst)
{
    dp[now]=max(dp[fa]+v[now]-cst,v[now]);
    ans=max(ans,dp[now]);
    for(int i=head[now];~i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs(e[i].to,now,e[i].val);
            dp[now]=max(dp[now],bk[e[i].to]+v[e[i].to]-e[i].val+v[now]);
            ans=max(ans,dp[now]);
        }
    bk[fa]=max(bk[fa],v[now]+bk[now]-cst);
}

int main()
{
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    memset(bk,0,sizeof(bk));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    dfs(1,-1,0);
    printf("%lld",ans);
    return 0;
}
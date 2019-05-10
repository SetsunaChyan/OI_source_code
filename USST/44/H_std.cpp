#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,head[1000005],tot=0,ansnum;
ll cnt[1000005],dp[1000005],ans;
struct edge
{
    int to,nxt;
    ll val;
}e[2000005];

void add_edge(int x,int y,ll z)
{
    e[tot].nxt=head[x];
    e[tot].to=y;
    e[tot].val=z;
    head[x]=tot;
    tot++;
}

void dfs1(int rt,int now,int fa)
{
    cnt[now]=1;
    for(int i=head[now];~i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs1(rt,e[i].to,now);
        cnt[now]+=cnt[e[i].to];
        dp[rt]+=cnt[e[i].to]*e[i].val;
    }
}

void dfs2(int rt,int now,int fa,ll dis)
{
    if(now!=rt) dp[now]=dp[fa]+(n-2*cnt[now])*dis;
    if(dp[now]<ans||dp[now]==ans&&now<ansnum)
        ans=dp[now],ansnum=now;
    for(int i=head[now];~i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs2(rt,e[i].to,now,e[i].val);
    }
}

int main()
{
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dfs1(1,1,0);
    ans=dp[1],ansnum=1;
    dfs2(1,1,0,0);
    printf("%d\n%lld",ansnum,2*ans);
    return 0;
}
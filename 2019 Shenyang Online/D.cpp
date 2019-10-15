#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
int n;
ll dp[100005][3],ans[3];
vector<int> e[10005];
vector<ll> v[10005];

void dfs1(int now,int fa)
{
    dp[now][0]=1,dp[now][1]=dp[now][2]=0;
    ll dis;
    int to;
    for(int i=0;i<e[now].size();i++)
    {
        to=e[now][i];
        if(to==fa) continue;
        dis=v[now][i]%3;
        dfs1(to,now);
        for(int j=0;j<3;j++)
            dp[now][j]+=dp[to][(j-dis+3)%3];
    }
}

void dfs2(int now,int fa)
{
    //printf("QAQ %d %lld %lld %lld\n",now,dp[now][0],dp[now][1],dp[now][2]);
    ll dis,d;
    int to;
    for(int i=0;i<e[now].size();i++)
    {
        to=e[now][i],dis=v[now][i],d=dis%3;
        //for(int s=0;s<3;s++)
        //    ans[s]+=dp[to][s]*(dp[now][(s-d+3)%3]-dp[to][(s-2*d+6)%3])%mod*dis%mod,ans[s]%=mod;
        for(int s1=0;s1<3;s1++)
            for(int s2=0;s2<3;s2++)
                ans[(s1+s2+d)%3]+=dp[to][s1]*(dp[now][s2]-dp[to][(s2-d+3)%3])%mod*dis%mod,ans[(s1+s2+d)%3]%=mod;
    }
    ll tmp_now[3],tmp_to[3];
    for(int i=0;i<3;i++) tmp_now[i]=dp[now][i];
    for(int i=0;i<e[now].size();i++)
    {
        to=e[now][i];
        if(to==fa) continue;
        dis=v[now][i]%3;
        for(int j=0;j<3;j++) tmp_to[j]=dp[to][j];
        for(int j=0;j<3;j++) dp[to][j]+=dp[now][(j-dis+3)%3]-tmp_to[(j-2*dis+6)%3];
        for(int j=0;j<3;j++) dp[now][j]-=tmp_to[(j-dis+3)%3];
        dfs2(to,now);
        for(int j=0;j<3;j++) dp[to][j]=tmp_to[j];
        for(int j=0;j<3;j++) dp[now][j]=tmp_now[j];
    }
}

void solve()
{
    ans[0]=ans[1]=ans[2]=0;
    for(int i=0;i<n;i++)
        e[i].clear(),v[i].clear();
    for(int i=1,x,y,w;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        e[x].push_back(y);
        e[y].push_back(x);
        v[x].push_back(w);
        v[y].push_back(w);
    }
    dfs1(0,0);
    dfs2(0,0);
    printf("%lld %lld %lld\n",ans[0]%mod,ans[1]%mod,ans[2]%mod);
}

int main()
{
    while(~scanf("%d",&n)) solve();
    return 0;
}

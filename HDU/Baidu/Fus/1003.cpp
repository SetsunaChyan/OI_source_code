#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n,l[100005],r[100005],cntp[100005],rt,flag[100005],siz[100005];
int ans[100005];
ll qaq[100005];
vector<int> dfsx;

int dfs0(int now)
{
    int lc,rc;
    siz[now]=1;
    lc=rc=0x3f3f3f3f;
    if(l[now]) lc=min(lc,dfs0(l[now])),siz[now]+=siz[l[now]];
    if(r[now]) rc=min(rc,dfs0(r[now])),siz[now]+=siz[r[now]];
    if(rc>now&&lc>now)
    {
        if(siz[r[now]]<siz[l[now]]) flag[now]=1;
        if(siz[r[now]]==siz[l[now]]&&rc<lc) flag[now]=1;
        return now;
    }
    if(rc<lc) flag[now]=1;
    return min(now,min(lc,rc));
}

void dfs(int now)
{
    if(!flag[now])
    {
        if(l[now]) dfs(l[now]);
        dfsx.push_back(now);
        if(r[now]) dfs(r[now]);
    }
    else
    {
        if(r[now]) dfs(r[now]);
        dfsx.push_back(now);
        if(l[now]) dfs(l[now]);
    }
}

void solve()
{
    dfsx.clear();
    for(int i=0;i<=n;i++) cntp[i]=0,flag[i]=0,siz[i]=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",l+i,r+i);
        cntp[l[i]]++,cntp[r[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!cntp[i]) rt=i;
    dfs0(rt);
    dfs(rt);
    for(int i=1;i<=n;i++)
        ans[dfsx[i-1]]=i;
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=(ans[i]^i)*qaq[i],sum%=mod;
    //for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    //printf("\n");
    printf("%lld\n",sum);
}

signed main()
{
    int _;
    qaq[1]=233;
    for(int i=2;i<=100000;i++)
        qaq[i]=qaq[i-1]*233%mod;
    scanf("%lld",&_);
    while(_--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

int n,m,qq,mk,ask[50005],tot;
ll ans[100005];
vector<int> e[50005];
vector<ll> val[50005];
queue<pli> q;

bool check(ll x)
{
    while(!q.empty()) q.pop();
    tot=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<e[i].size();j++)
        {
            if(val[i][j]<=x) q.emplace(val[i][j],e[i][j]),ans[++tot]=val[i][j];
            if(tot>=mk) return true;
        }
    while(!q.empty())
    {
        int now=q.front().second;
        ll vv=q.front().first;
        q.pop();
        for(int j=0;j<e[now].size();j++)
            if(val[now][j]+vv<=x) q.emplace(val[now][j]+vv,e[now][j]),ans[++tot]=vv+val[now][j];
        if(tot>=mk) return true;
    }
    return false;
}

void solve()
{
    mk=0;
    scanf("%d%d%d",&n,&m,&qq);
    for(int i=1;i<=n;i++) e[i].clear(),val[i].clear();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        e[x].push_back(y),val[x].push_back(z);
    }
    for(int i=0;i<qq;i++)
    {
        scanf("%d",ask+i);
        mk=max(mk,ask[i]);
    }
    ll l=1,r=5e6,mid;
    while(l<r)
    {
        mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    check(l);
    sort(ans+1,ans+mk+1);
    //printf("qaq %d\n",mk);
    //for(int i=1;i<=mk;i++)
    //    printf("%lld ",ans[i]);
    //printf("\n");
    for(int i=0;i<qq;i++)
        printf("%lld\n",ans[ask[i]]);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

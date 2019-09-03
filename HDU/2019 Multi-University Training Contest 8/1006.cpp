#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=0x7fffffffffffffff;
vector<int> e[100005];
int n;
ll a[100005],b[100005],v[100005],va[100005],vb[100005],dpa[100005],dpb[100005],ans;

void dfs1(int now,int fa)
{
    va[now]=vb[now]=0;
    for(auto to:e[now])
        if(to!=fa)
        {
            dfs1(to,now);
            va[now]=max(va[now],vb[to]);
            vb[now]=min(vb[now],va[to]);
        }
    va[now]+=v[now];
    vb[now]+=v[now];
}

void dfs2(int now,int fa)
{
    if(now!=fa)
    {
        dpa[now]=dpb[fa]-va[fa]+vb[fa]+vb[now]-va[now];
        dpb[now]=dpa[fa]-vb[fa]+va[fa]+va[now]-vb[now];
    }
    ans=max(ans,dpa[now]);
    for(auto to:e[now])
        if(to!=fa) dfs2(to,now);
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    for(int i=1;i<=n;i++) scanf("%lld",b+i);
    for(int i=1;i<=n;i++) v[i]=a[i]-b[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,1);
    ans=dpa[1]=va[1];
    dpb[1]=vb[1];
    dfs2(1,1);
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

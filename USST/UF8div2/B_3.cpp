#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll s[100005],ans,qaq[100005],a[100005],sum[100005];
vector<int> e[100005];

void chk(int now,int fa,ll mx)
{
    if(s[now]!=-1&&s[now]<mx)
    {
        ans=-1;
        return;
    }
    ll nmx=mx;
    if(s[now]!=-1) nmx=s[now];
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        chk(to,now,nmx);
        if(ans==-1) return;
    }
}

ll dfs(int now,int fa)
{
    if(s[now]!=-1) qaq[now]=s[now];
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        ll tmp=dfs(to,now);
        if(tmp==0&&s[now]==-1) qaq[now]=min(qaq[now],tmp);
        else if(tmp!=0) qaq[now]=min(qaq[now],tmp);
    }
    if(qaq[now]==0x3f3f3f3f3f3f3f3fll) qaq[now]=0;
    return qaq[now];
}

void dfs2(int now,int fa)
{
    if(qaq[now]<=sum[fa]) a[now]=0; else a[now]=qaq[now]-sum[fa];
    sum[now]=sum[fa]+a[now];
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        dfs2(to,now);
    }
}

int main()
{
    scanf("%d",&n);
    memset(qaq,0x3f,sizeof(qaq));
    for(int i=2,x;i<=n;i++)
        scanf("%d",&x),e[i].push_back(x),e[x].push_back(i);
    e[0].push_back(1);
    for(int i=1;i<=n;i++)
        scanf("%lld",s+i);
    chk(1,1,0);
    if(ans==-1) return printf("-1"),0;
    dfs(0,0);
    dfs2(1,1);
    for(int i=1;i<=n;i++) ans+=a[i];
    printf("%lld",ans);
    return 0;
}

/*
8
1 1 2 2 3 3 4
5 6 6 10 7 6 9 12

4
1 2 2
0 -1 8 7
*/

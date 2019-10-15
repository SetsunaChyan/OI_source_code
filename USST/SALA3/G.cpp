#include <bits/stdc++.h>
using namespace std;

int n,c[300005],blue,red,r[300005],b[300005],ans;
vector<int> e[300005];

void dfs1(int now,int fa)
{
    if(c[now]==1) r[now]++;
    else if(c[now]==2) b[now]++;
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs1(to,now);
        r[now]+=r[to];
        b[now]+=b[to];
    }
}

void dfs2(int now,int fa)
{
    for(auto to:e[now])
    {
        if(to==fa) continue;
        if(r[to]==0&&b[to]==blue||r[to]==red&&b[to]==0) ans++;
        dfs2(to,now);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        if(c[i]==1) red++;
        else if(c[i]==2) blue++;
    }
    for(int i=0,u,v;i<n-1;i++)
        scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
    dfs1(1,1);
    dfs2(1,1);
    printf("%d",ans);
    return 0;
}

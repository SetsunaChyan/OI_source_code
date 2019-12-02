#include <bits/stdc++.h>
using namespace std;

int n,a[200005],vis[200005],ans[200005];

int dfs(int now,int dep)
{
    vis[now]=1;
    if(vis[a[now]]) return ans[now]=dep+1;
    return ans[now]=dfs(a[now],dep+1);
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),vis[i]=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]) ans[i]=dfs(i,0);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

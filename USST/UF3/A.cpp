#include <bits/stdc++.h>
using namespace std;

int n,r1,r2,fa[50005];
vector<int> e[50005];

void dfs(int now,int f)
{
    fa[now]=f;
    for(auto to:e[now])
        if(to!=f) dfs(to,now);
}

int main()
{
    scanf("%d%d%d",&n,&r1,&r2);
    for(int i=1,x;i<=n;i++)
    {
        if(i==r1) continue;
        scanf("%d",&x);
        e[x].push_back(i);
        e[i].push_back(x);
    }
    dfs(r2,r2);
    for(int i=1;i<=n;i++)
    {
        if(i==r2) continue;
        printf("%d ",fa[i]);
    }
    return 0;
}

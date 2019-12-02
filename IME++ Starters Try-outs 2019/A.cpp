#include <bits/stdc++.h>
using namespace std;

int dis[2005],vis[2005],n,m,ans;
vector<int> e[2005];

void bfs(int s)
{
    queue<int> q;
    for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
    dis[s]=0,q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(auto to:e[now])
            if(dis[to]>dis[now]+1)
                dis[to]=dis[now]+1,q.push(to);
    }
    for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++) bfs(i);
    if(ans<0x3f3f3f3f)
        printf("=] %d",ans);
    else
        printf("=[");
    return 0;
}

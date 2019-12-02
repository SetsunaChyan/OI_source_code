#include <bits/stdc++.h>
using namespace std;

int n,m,ans,tot,flag,vis[2005];
vector<int> like[2005],dislike[2005];

void dfs(int now,int op)
{
    vis[now]=op;tot++;
    for(auto to:like[now])
        if(!vis[to]) dfs(to,op);
    for(auto to:dislike[now])
        if(vis[to]==vis[now]) flag=0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        like[x].push_back(y);
        like[y].push_back(x);
    }
    scanf("%d",&m);
    for(int i=0,x,y;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        dislike[x].push_back(y);
        dislike[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            tot=0,flag=1;
            dfs(i,i);
            if(flag) ans=max(tot,ans);
        }
    printf("%d",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,m,deg[5005],cnt;
vector<int> e[5005],ans;
queue<int> q;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        deg[v]++;
        e[u].push_back(v);
        ans.push_back((u<v)+1);
    }
    for(int i=1;i<=n;i++)
        if(!deg[i]) q.push(i);
    while(!q.empty())
    {
        cnt++;
        int now=q.front();q.pop();
        for(auto to:e[now])
            if(--deg[to]==0) q.push(to);
    }
    if(cnt==n)
    {
        printf("1\n");
        for(int i=0;i<m;i++) printf("1 ");
        return 0;
    }
    printf("2\n");
    for(auto p:ans) printf("%d ",p);
    return 0;
}

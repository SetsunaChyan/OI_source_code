#include <bits/stdc++.h>
using namespace std;
int n,m,c[102],d[102],sz[102][102],p[102];
vector<int>g[102];
void dfs(int u,int p)
{
    ::p[u]=p,d[u]=d[p]+1;for(auto v:g[u])if(v!=p)dfs(v);
}
void gao(int u,int p)
{N
    for(auto v:g[u])
        if(v!=p)
            for(int dep=0;)
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
    dfs(1,0);
    for(int i=1;i<=n;i++)
        if(c[i])
        {
            int t=i;
            while(p[t])
                sz[p[t]][d[i]-d[p[t]]++;
        }
    gao(1,0);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
    预处理 O(nlogn)
    单次查询 O(logn)
*/

const int MAXN=500005;
int n,q,dep[MAXN],s,lg[MAXN],fa[MAXN][32];
vector<int> e[MAXN];

void dfs(int now,int pa)
{
    dep[now]=dep[pa]+1;
    fa[now][0]=pa;
    for(int i=1;(1<<i)<=dep[now];i++)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(auto to:e[now])
        if(to!=pa) dfs(to,now);
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return x;
    for(int i=lg[dep[x]]-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

int main()
{
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    scanf("%d%d%d",&n,&q,&s);
    for(int i=0,x,y;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y),e[y].push_back(x);
    }
    dep[0]=0;
    dfs(s,0);
    for(int i=0,x,y;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}

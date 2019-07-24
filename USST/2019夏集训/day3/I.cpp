#include <bits/stdc++.h>
using namespace std;

int par[10005],val[10005][20],lg[10005],dep[10005],fa[10005][20],m,n,q,tot=0,vis[10005];
struct edge
{
    int x,y,z;
}e1[50005];
vector<int> e[10005],v[10005];

int _find(int x){return x==par[x]?x:par[x]=_find(par[x]);}
bool cmp(edge a,edge b){return a.z>b.z;}

void dfs(int now,int u,int col)
{
    dep[now]=dep[u]+1;
    fa[now][0]=u;
    vis[now]=col;
    for(int i=1;(1<<i)<=dep[now];i++)
        fa[now][i]=fa[fa[now][i-1]][i-1],val[now][i]=min(val[fa[now][i-1]][i-1],val[now][i-1]);
    for(int i=0;i<e[now].size();i++)
        if(!vis[e[now][i]])
        {
            val[e[now][i]][0]=v[now][i];
            dfs(e[now][i],now,col);
        }
}

int lca(int x,int y)
{
    int ret=0x3f3f3f3f;
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y])
        ret=min(ret,val[x][lg[dep[x]-dep[y]]-1]),x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return ret;
    for(int i=lg[dep[x]]-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
        {
            ret=min(ret,val[x][i]);
            ret=min(ret,val[y][i]);
            x=fa[x][i],y=fa[y][i];
        }
    ret=min(ret,val[x][0]);
    ret=min(ret,val[y][0]);
    return ret;
}


int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    lg[0]=0;
    for(int i=1;i<=n;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&e1[i].x,&e1[i].y,&e1[i].z);
    sort(e1,e1+m,cmp);
    for(int i=0;i<m;i++)
    {
        int x=_find(e1[i].x),y=_find(e1[i].y);
        if(x==y) continue;
        par[x]=y;
        e[e1[i].x].push_back(e1[i].y),v[e1[i].x].push_back(e1[i].z);
        e[e1[i].y].push_back(e1[i].x),v[e1[i].y].push_back(e1[i].z);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            tot++;
            dep[i]=0,val[i][0]=0x3f3f3f3f;
            dfs(i,i,tot);
        }
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(vis[x]!=vis[y])
            printf("-1\n");
        else
            printf("%d\n",lca(x,y));
    }
    return 0;
}

/*
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3
*/

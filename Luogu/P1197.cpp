#include <bits/stdc++.h>
using namespace std;

const int N=400005;
int fa[N],head[N],tot=0,vis[N],n,m,k,opt[N],ans[N],white=0;

struct edge
{
    int to,nxt;
}e[N<<1];

int _find(int x){return x==fa[x]?x:fa[x]=_find(fa[x]);}
void _union(int x,int y){fa[_find(x)]=fa[_find(y)];}

inline void add_edge(int x,int y)
{
    e[tot].nxt=head[x];
    e[tot].to=y;
    head[x]=tot;
    tot++;
}

void dfs(int now,int par)
{
    fa[now]=par;
    vis[now]=1;
    for(int i=head[now];~i;i=e[i].nxt)
    {
        if(vis[e[i].to]) continue;
        dfs(e[i].to,par);
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&opt[i]);
        vis[opt[i]]=2;
        fa[opt[i]]=opt[i];
    }
    for(int i=0;i<n;i++)
        if(!vis[i]) 
        {
            white++;
            dfs(i,i);
        }
    for(int i=k-1;i>=0;i--)
    {
        ans[i]=white;
        white++;
        vis[opt[i]]=1;
        for(int j=head[opt[i]];~j;j=e[j].nxt)
        {
            if(vis[e[j].to]==2) continue;
            if(_find(e[j].to)!=_find(opt[i]))
            {
                _union(e[j].to,opt[i]);
                white--;
            }
        }
    }
    printf("%d\n",white);
    for(int i=0;i<k;i++)
        printf("%d\n",ans[i]);
    return 0;
}

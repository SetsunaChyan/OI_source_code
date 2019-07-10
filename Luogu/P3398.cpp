#include <bits/stdc++.h>
using namespace std;

int n,q,tot=0,lg[100005],dep[100005],head[100005],fa[100005][32];
struct edge
{
    int to,nxt;
}e[100005<<1];

void add_edge(int x,int y)
{
    e[tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot++;
}

void dfs(int now,int f)
{
    dep[now]=dep[f]+1;
    fa[now][0]=f;
    for(int i=1;(1<<i)<=dep[now];i++)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=f) dfs(e[i].to,now);
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

int dis(int x,int y)
{
    int z=lca(x,y);
    return dep[x]+dep[y]-2*dep[z];
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    dep[0]=0;
    dfs(1,0);
    while(q--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int x=lca(a,b),y=lca(c,d),flag=0;
        if(dis(a,y)+dis(y,b)==dep[a]+dep[b]-2*dep[x]) flag=1;
        if(dis(c,x)+dis(x,d)==dep[c]+dep[d]-2*dep[y]) flag=1;
        printf("%c\n","NY"[flag]);
    }
    return 0;
}

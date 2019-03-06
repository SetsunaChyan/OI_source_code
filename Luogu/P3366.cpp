#include <cstdio>
#include <memory.h>
#include <algorithm>

int head[5000],n,m,root[5000],tot=0,ans=0,k=0;
struct edge
{
    int x,y,v;
}e[400000];

inline bool cmp(edge a,edge b){return a.v<b.v;}

void add(int x,int y,int v)
{
    e[tot].x=x,e[tot].y=y,e[tot].v=v;
    tot++;
}

int find(int x)
{
    if(root[x]==x) return x;
    return root[x]=find(root[x]);
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        root[i]=i;
    for(int i=0;i<m;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        add(x-1,y-1,v);
        add(y-1,x-1,v);
    }
    std::sort(e,e+tot,cmp);
    for(int i=0;i<tot;i++)
    {
        if(find(e[i].x)!=find(e[i].y))
        {
            k++;
            ans+=e[i].v;
            root[find(e[i].x)]=e[i].y;
        }
    }
    if(k==n-1) printf("%d",ans); else printf("orz");
    return 0;
}
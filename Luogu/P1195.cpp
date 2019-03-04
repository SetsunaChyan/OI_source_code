#include <cstdio>
#include <algorithm>

int n,m,k,par[1000],ans=0;
struct edge
{
    int u,v,w;
}e[10000];

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void u(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if(x!=y) par[y]=x;
}

int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        par[i]=i;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        e[i].u--;
        e[i].v--;
    }
    std::sort(e,e+m,cmp);
    for(i=n-k,j=0;i!=0&&j<m;j++)
    {
        if(find(e[j].u)!=find(e[j].v))
        {
            i--;
            u(e[j].u,e[j].v);
            ans+=e[j].w;
        }
    }
    if(i==0)
        printf("%d\n",ans);
    else
        printf("No Answer\n");
    return 0;
}

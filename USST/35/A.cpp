#include <cstdio>
#include <memory.h>

int n,m,head[10005],tot=0,cost[10005];
struct node
{
    int a,b,c;
}pf[100005];
struct edge
{
    int next,to;
}e[400005];

inline void add(int x,int y)
{
    e[tot].next=head[x];
    e[tot].to=y;
    head[x]=tot++;
}

void dfs(int now)
{
    if(cost[pf[now].a]+cost[pf[now].b]>=cost[pf[now].c]) return;
    cost[pf[now].c]=cost[pf[now].a]+cost[pf[now].b];
    for(int i=head[pf[now].c];~i;i=e[i].next)
        dfs(e[i].to);
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&cost[i]);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&pf[i].c,&pf[i].a,&pf[i].b);
        pf[i].a--,pf[i].b--,pf[i].c--;
        add(pf[i].a,i);
        add(pf[i].b,i);
    }
    for(int i=0;i<m;i++)
        dfs(i);
    printf("%d",cost[0]);
    return 0;
}
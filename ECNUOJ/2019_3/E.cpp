#include <cstdio>
#include <memory.h>

int tot=0,head[105],n,fa[105],root=0,p,q;
double dp[200][2],val[200],dec[200];
struct edge
{
    int to,next;
}e[300];

inline void addedge(int x,int y)
{
    e[tot].next=head[x];
    e[tot].to=y;
    head[x]=tot++;
}

void dfs1(int now,double b,int dis)
{
    dec[now]+=b/dis;
    if(fa[now]) dfs1(fa[now],b,dis+1);
}

int main()
{
    memset(fa,0,sizeof(fa));
    memset(dp,0,sizeof(dp));
    memset(dec,0,sizeof(dec));
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        fa[i+1]=x;
        addedge(x,i+1);
    }
    scanf("%d%d",&p,&q);
    for(int i=0;i<p;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        dec[x]=y;
    }
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==0)
        {
            root=i;
            continue;
        }
        dfs1(i,dec[i],1);
    }
    dfs2(root);
    printf("%lf",max(dp[root][q][0],dp[root][q][1]));
    return 0; 
}
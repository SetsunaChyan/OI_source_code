#include <cstdio>
#include <memory.h>

const int MAXN=1005;
int vis[MAXN],head[MAXN],tot=1,x[MAXN],y[MAXN],front[MAXN],p,hd,hd_d=-1,d[MAXN],path[MAXN],n,m;
struct edge
{
    int next,to;
}e[MAXN<<1];

inline void addedge(int a,int b)
{
    e[tot].next=head[a];
    e[tot].to=b;
    head[a]=tot;
    tot++;
}

void dfs(int now,int fa,int dep)
{
    vis[now]=1;
    d[now]=dep;
    front[now]=fa;
    if(dep>=d[p]) p=now;
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=fa)
            dfs(e[i].to,now,dep+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    memset(head,0,sizeof(head));
    for(int i=0;i<m;i++)
    {
        int q,w;
        scanf("%d%d",&q,&w);
        addedge(q,w);
        addedge(w,q);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            p=i;
            dfs(i,0,0);
            dfs(p,0,0); 
            if(d[p]>hd_d)
            {
                hd_d=d[p];
                hd=p;
            }
        }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n-m-1;i++)
    {
        p=hd;
        dfs(hd,0,0);
        dfs(p,0,0);
        for(int now=p,j=0;now;now=front[now],j++)
            path[j]=now;
        x[i]=path[d[p]/2];
        for(int j=1;j<=n;j++)
            if(!vis[j])
            {
                p=j;
                dfs(j,0,0);
                dfs(p,0,0);
                for(int now=p,j=0;now;now=front[now],j++)
                    path[j]=now;
                y[i]=path[d[p]/2];
                addedge(x[i],y[i]);
                addedge(y[i],x[i]);
                break;
            }
    }
    p=1;
    dfs(1,0,0);
    dfs(p,0,0);
    printf("%d\n",d[p]);
    for(int i=0;i<n-m-1;i++)
        printf("%d %d\n",x[i],y[i]);
    return 0;
}
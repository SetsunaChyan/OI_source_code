#include <cstdio>
#include <memory.h>

const int INF=0x3f3f3f3f;
int e[505][505],n,m,head,end,vis[505],ans;
struct node
{
    int x,dep;
}s[505];

inline int max(int a,int b){return a>b?a:b;}

int bfs(int st)
{
    head=0,end=1;
    memset(vis,0,sizeof(vis));
    s[0].x=1,s[0].dep=0,vis[1]=1;
    do
    {
        for(int i=1;i<=n;i++)
            if(i!=s[head].x&&e[s[head].x][i]==st&&!vis[i])
            {
                vis[i]=1;
                s[end].x=i;
                s[end].dep=s[head].dep+1;
                if(i==n) return s[end].dep;
                end++;
            }
        head++;
    }while(head<end);
    return INF;
}

int main()
{
    memset(e,0,sizeof(e));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=e[y][x]=1;
    }
    ans=max(bfs(1),bfs(0));
    if(ans==INF)
        printf("-1");
    else
        printf("%d",ans);
    return 0;
}

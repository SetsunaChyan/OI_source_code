#include <cstdio>

int n,vis[10],sel[10];

void dfs(int x)
{
    if(x==n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%d ",sel[i]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
        if(vis[i])
        {
            vis[i]=0;
            sel[x]=i;
            dfs(x+1);
            vis[i]=1;
        }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) vis[i]=1;
    dfs(1);
    return 0;
}

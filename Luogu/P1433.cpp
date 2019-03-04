#include <cstdio>
#include <memory.h>
#include <cmath>

int n,vis[16];
double ans=1e10,m[16][16],x[16],y[16];

void dfs(int k,int now,double sum)
{
    if(k==n)
    {
        ans=sum<ans?sum:ans;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(m[now][i]+sum>=ans) continue;
        vis[i]=1;
        dfs(k+1,i,m[now][i]+sum);
        vis[i]=0;
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    memset(m,0,sizeof(m));
    scanf("%d",&n);
    x[0]=y[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            m[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    dfs(0,0,0);
    printf("%.2lf",ans);
    return 0;
}
#include <cstdio>
#include <memory.h>

int n,m,deg[11],qq[11],wx[11],ans;
struct edge
{
    int a,b;
}e[100];

void dfs(int dep)
{
    if(dep==m)
    {
        ans++;
        return;
    }
    if(deg[e[dep].b]&1) return;
    if(deg[e[dep].a]&1) return;
    if(qq[e[dep].b]<deg[e[dep].b]/2&&qq[e[dep].a]<deg[e[dep].a]/2)
    {
        qq[e[dep].b]++;
        qq[e[dep].a]++;
        dfs(dep+1);
        qq[e[dep].b]--;
        qq[e[dep].a]--;
    }
    if(wx[e[dep].b]<deg[e[dep].b]/2&&wx[e[dep].a]<deg[e[dep].a]/2)
    {
        wx[e[dep].b]++;
        wx[e[dep].a]++;
        dfs(dep+1);
        wx[e[dep].b]--;
        wx[e[dep].a]--;
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        memset(deg,0,sizeof(deg));
        memset(qq,0,sizeof(qq));
        memset(wx,0,sizeof(wx));
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&e[i].a,&e[i].b);
            deg[e[i].a]++,deg[e[i].b]++;
        }
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;   
}
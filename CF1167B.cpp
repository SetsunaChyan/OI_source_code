#include <bits/stdc++.h>
using namespace std;

const int p[]={0,4,8,15,16,23,42};
int a[7][7],b,ans[7],vis[7],flag=0;

void ask(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    scanf("%d",&b);
    a[x][y]=a[y][x]=b;
}

void dfs(int dep)
{
    if(dep==7)
    {
        for(int i=1;i<5;i++)
            if(ans[i]*ans[i+1]!=a[i][i+1]) return;
        flag=1;
        printf("! ");
        for(int i=1;i<=6;i++)
            printf("%d ",ans[i]);
    }
    for(int i=1;i<=6;i++)
    {
        if(vis[i]) continue;
        vis[i]=1;
        ans[dep]=p[i];
        dfs(dep+1);
        vis[i]=0;
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    ask(1,2);
    ask(2,3);
    ask(3,4);
    ask(4,5);
    dfs(1);
    fflush(stdout);
    return 0;
}
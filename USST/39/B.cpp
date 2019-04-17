#include <cstdio>
#include <memory.h>

int n,m,x,y;
char s[1005][1005];
int vis[1005][1005];
const int mv[4][2]={1,0,0,1,-1,0,0,-1};
int cnt=0;

void dfs(int x,int y)
{
    vis[x][y]=1;
    if(s[x][y]=='r')
    {
        s[x][y]='$';
        cnt+=100;
    }
    else if(s[x][y]=='R')
    {
        s[x][y]='#';
        cnt+=10;
    }
    else return;
    for(int i=0;i<4;i++)
    {
        int dx=mv[i][0]+x;
        int dy=mv[i][1]+y;
        if(dx<0||dx>=n||dy<0||dy>=m||vis[dx][dy]) continue;
        dfs(dx,dy);
    }
}

int main()
{
    memset(vis,0,sizeof vis);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    scanf("%d%d",&x,&y);
    if(s[x][y]=='R'||s[x][y]=='r')
        dfs(x,y);
    for(int i=0;i<n;i++)
        printf("%s\n",s[i]);
    printf("%d",cnt);
    return 0;
}
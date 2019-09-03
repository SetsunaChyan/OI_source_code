#include <bits/stdc++.h>
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4,t[5];
int vis[15][15];
const int mov[4][2]={1,0,0,1,-1,0,0,-1};

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int dx=mov[i][0]+x,dy=mov[i][1]+y;
        if(dx>=0&&dx<15&&dy>=0&&dy<15&&!vis[dx][dy]) dfs(dx,dy);
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int ans=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
        memset(vis,0,sizeof(vis));
        t[0]=x1,t[1]=x2,t[2]=x3,t[3]=x4;
        sort(t,t+4);
        x1=(lower_bound(t,t+4,x1)-t+1)*2;
        x2=(lower_bound(t,t+4,x2)-t+1)*2;
        x3=(lower_bound(t,t+4,x3)-t+1)*2;
        x4=(lower_bound(t,t+4,x4)-t+1)*2;
        t[0]=y1,t[1]=y2,t[2]=y3,t[3]=y4;
        sort(t,t+4);
        y1=(lower_bound(t,t+4,y1)-t+1)*2;
        y2=(lower_bound(t,t+4,y2)-t+1)*2;
        y3=(lower_bound(t,t+4,y3)-t+1)*2;
        y4=(lower_bound(t,t+4,y4)-t+1)*2;
        for(int i=x1;i<=x2;i++) vis[i][y1]=vis[i][y2]=1;
        for(int i=y1;i<=y2;i++) vis[x1][i]=vis[x2][i]=1;
        for(int i=x3;i<=x4;i++) vis[i][y3]=vis[i][y4]=1;
        for(int i=y3;i<=y4;i++) vis[x3][i]=vis[x4][i]=1;
        for(int i=0;i<15;i++)
            for(int j=0;j<15;j++)
                if(!vis[i][j])
                {
                    ans++;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }

    return 0;
}

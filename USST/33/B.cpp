#include <cstdio>
#include <algorithm>

const int move[4][2]={1,0,0,1,-1,0,0,-1};
int r,c,a[105][105],tot=0,ans=0,dp[105][105];
struct node
{
    int h,x,y;
}e[10050];

inline bool cmp(node a,node b){return a.h<b.h;}
inline int max(int a,int b){return a>b?a:b;}

inline void update(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int dx=x+move[i][0],dy=y+move[i][1];
        if(dx>=0&&dx<r&&dy>=0&&dy<c&&a[dx][dy]<a[x][y])
            dp[x][y]=max(dp[x][y],dp[dx][dy]+1);
    }
}

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
            dp[i][j]=1;
            e[tot].x=i;
            e[tot].y=j;
            e[tot].h=a[i][j];
            tot++;
        }
    std::sort(e,e+tot,cmp);
    for(int i=0;i<tot;i++)
    {
        update(e[i].x,e[i].y);
        ans=max(ans,dp[e[i].x][e[i].y]);
    }
    printf("%d",ans);
    return 0;
}
#include <cstdio>

const int move[4][2]={1,0,-1,0,0,1,0,-1};

char s[101][101];
int a,b,ans=0;

void dfs(int x,int y)
{
    s[x][y]='.';
    for(int i=0;i<4;i++)
    {
        int dx=x+move[i][0],dy=y+move[i][1];
        if(dx>=0&&dx<a&&dy>=0&&dy<b&&s[dx][dy]=='#')
        {
            dfs(dx,dy);
        }
    }
}

int main()
{
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++)
        scanf(" %s",s[i]);
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
        {
            if(s[i][j]=='#')
            {
                ans++;
                dfs(i,j);
            }
        }
    printf("%d",ans);
    return 0;
}

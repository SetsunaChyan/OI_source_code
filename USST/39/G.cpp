#include <cstdio>

const int mv[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;
char s[505][505];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='w')
                for(int k=0;k<4;k++)
                {
                    int dx=i+mv[k][0],dy=j+mv[k][1];
                    if(dx>=0&&dx<n&&dy>=0&&dy<m&&s[dx][dy]=='s')
                    {
                        printf("No");
                        return 0;
                    }
                }
    printf("Yes\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(s[i][j]=='.') printf("d"); else printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}
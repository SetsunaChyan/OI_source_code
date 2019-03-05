#include <cstdio>

char opt,b[150][150],s[150][150];
int n,flag=1;

int main()
{
    scanf("%c%d",&opt,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%*c");
        for(int j=0;j<n;j++)
        {
            scanf("%c",&s[i][j]);
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(s[i][j]!=s[n-i-1][n-j-1]) flag=0;
            if(s[n-i-1][n-j-1]==' ')
                b[i][j]=' ';
            else
                b[i][j]=opt;
        }
    if(flag) printf("bu yong dao le\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%c",b[i][j]);
        printf("\n");
    }

    return 0;
}
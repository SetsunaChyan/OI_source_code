#include <cstdio>

int con,l,n,a,b,mp[1000][1000];

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    if(a!=1&&b!=1) {printf("NO");return 0;}
    if(n==2&&a+b!=3) {printf("NO");return 0;}
    if(n==3&&a==1&&b==1) {printf("NO");return 0;}
    if(a==1) {con=1;l=b;} else {con=0;l=a;}
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) {mp[i][j]=0;continue;}
            mp[i][j]=con;
        }
    for(int i=0;i<n-l;i++)
        mp[i+1][i]=mp[i][i+1]=con^1;
    printf("YES");
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
            printf("%d ",mp[i][j]);
    }
    return 0;
}
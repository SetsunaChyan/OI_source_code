#include <bits/stdc++.h>
using namespace std;

int a[1005][1005],p[1005][1005],n,m;

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&p[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int k=p[i][j]&1;
            a[i-1][j]^=k;
            a[i][j-1]^=k;
            a[i+1][j]^=k;
            a[i][j+1]^=k;
            a[i][j]^=k;
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d",a[i][j]^1);
        printf("\n");
    }
    return 0;
}
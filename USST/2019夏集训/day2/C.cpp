#include <bits/stdc++.h>
using namespace std;

int a[105][105],sum[105][105],t,ans=0,n,m;

int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    for(int i=1;i<=min(n,10);i++)
        for(int j=1;j<=min(m,10);j++)
            for(int x=i;x<=n;x++)
                for(int y=j;y<=m;y++)
                    ans=max(ans,sum[x][y]+sum[x-i][y-j]-sum[x][y-j]-sum[x-i][y]-i*j*t);
    printf("%d",ans);
    return 0;
}

/*
5 3 5
2 6 3
10 6 6
5 2 4
1 5 9
10 4 3
*/

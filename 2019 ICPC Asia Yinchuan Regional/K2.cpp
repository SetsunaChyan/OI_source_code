#include <bits/stdc++.h>
using namespace std;

int n,m,a[1005][1005],b[1005][1005],l[1005][1005],r[1005][1005],up[1005][1005],ans;
int x[1005*1005],y[1005*1005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            a[i][j]=-1,b[i][j]=-2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),l[i][j]=j,r[i][j]=j,up[i][j]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&b[i][j]);
            x[b[i][j]]=i,y[b[i][j]]=j;
        }
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            if(a[i][j-1]==b[x[a[i][j]]][y[a[i][j]]-1]) l[i][j]=l[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=m-1;j>=1;j--)
            if(a[i][j+1]==b[x[a[i][j]]][y[a[i][j]]+1]) r[i][j]=r[i][j+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i>1&&a[i-1][j]==b[x[a[i][j]]-1][y[a[i][j]]])
            {
                l[i][j]=max(l[i-1][j],l[i][j]);
                r[i][j]=min(r[i-1][j],r[i][j]);
                up[i][j]=up[i-1][j]+1;
            }
            ans=max(ans,(r[i][j]-l[i][j]+1)*up[i][j]);
        }
    printf("%d",ans);
    return 0;
}

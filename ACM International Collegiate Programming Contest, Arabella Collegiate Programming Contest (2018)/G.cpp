#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,ans,a[505][505],b[505][505],c[505][505],d[505][505],g[505][505],t[4];

void gao()
{
    ans=0x3f3f3f3f;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            a[i][j]=b[i][j]=c[i][j]=d[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=max(g[i][j],max(a[i-1][j],a[i][j-1]));
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            b[i][j]=max(g[i][j],max(b[i-1][j],b[i][j+1]));
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            c[i][j]=max(g[i][j],max(c[i+1][j],c[i][j-1]));
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            d[i][j]=max(g[i][j],max(d[i+1][j],d[i][j+1]));
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
        {
            t[0]=a[i-1][j-1];
            t[1]=b[i-1][j+1];
            t[2]=c[i+1][j-1];
            t[3]=d[i+1][j+1];
            sort(t,t+4);
            ans=min(ans,t[3]-t[0]);
        }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) gao();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int a[105][105],vis[105][105],n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int ans=0;
    for(int i=0;i<n;i++)
        if(!vis[n/2][i])
            ans+=a[n/2][i],vis[n/2][i]=1;
    for(int i=0;i<n;i++)
        if(!vis[i][n/2])
            ans+=a[i][n/2],vis[i][n/2]=1;
    for(int i=0;i<n;i++)
        if(!vis[i][i])
            ans+=a[i][i],vis[i][i]=1;
    for(int i=0;i<n;i++)
        if(!vis[n-i-1][i])
            ans+=a[n-i-1][i],vis[n-i-1][i]=1;
    printf("%d",ans);
    return 0;
}

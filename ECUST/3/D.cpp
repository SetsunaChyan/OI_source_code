#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[2005][2005],h[2005][2005],w[2005][2005],dp[2005][2005];
ll ans=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&a[i][j]);
    for(int i=0;i<n;i++)
    {
        h[i][0]=a[i][0];
        for(int j=1;j<n;j++)
            h[i][j]=a[i][j]?h[i][j-1]+1:0;
    }
    for(int i=0;i<n;i++)
    {
        w[0][i]=a[0][i];
        for(int j=1;j<n;j++)
            w[j][i]=a[j][i]?w[j-1][i]+1:0;
    }
    dp[0][0]=a[0][0];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i&&j) dp[i][j]=min(dp[i-1][j-1]+1,min(h[i][j],w[i][j])); else dp[i][j]=a[i][j];
            ans+=dp[i][j];
        }
    printf("%lld",ans);
    return 0;
}

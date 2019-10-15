#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,tt;
ll a[55],dp[55][55][55];

int main()
{
    scanf("%d%d",&n,&tt);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i),dp[i][i][0]=a[i];
    tt--;
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            for(int k=j;k<i+j;k++)
            {
                dp[j][i+j][0]=max(dp[j][i+j][0],dp[j][k][0]+dp[k+1][i+j][0]);
                for(int t=1;t<i;t++)
                    for(int g=1;g<=t;g++)
                        dp[j][i+j][t]=max(dp[j][i+j][t],dp[j][k][g-1]&dp[k+1][i+j][t-g]);
            }
    printf("%lld",dp[0][n-1][tt]);
    return 0;
}

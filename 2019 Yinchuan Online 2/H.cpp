#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
ll dp[100050][6],a[100050];
int n;
char s[100050];

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<6;i++)
        dp[0][i]=0;
    if(s[0]=='w') {dp[0][0]=a[0];}
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<5;j++)
            dp[i][j]=dp[i-1][j];
        if(s[i]=='w')
        {
            dp[i][0]=dp[i-1][0]+a[i];
            dp[i][1]=min(dp[i-1][0],dp[i][1]);
        }
        if(s[i]=='r')
        {
            dp[i][1]=dp[i-1][1]+a[i];
            dp[i][2]=min(dp[i-1][1],dp[i][2]);
        }
        if(s[i]=='o')
        {
            dp[i][2]=dp[i-1][2]+a[i];
            dp[i][3]=min(dp[i-1][2],dp[i][3]);
        }
        if(s[i]=='n')
        {
            dp[i][3]=dp[i-1][3]+a[i];
            dp[i][4]=min(dp[i-1][3],dp[i][4]);
        }
        if(s[i]=='g')
        {
            dp[i][4]=dp[i-1][4]+a[i];
        }
    }
    ll ans=0x3f3f3f3f3f3f3f3fll;
    for(int i=0;i<5;i++)
        ans=min(ans,dp[n-1][i]);
    printf("%lld",ans);
    return 0;
}

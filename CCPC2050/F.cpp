#include <cstdio>
#include <memory.h>

typedef long long ll;
ll dp[1005][1005];
int n,c;

inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&c);
        dp[0][0]=c;
        for(int i=1;i<=n;i++)
        {
            ll a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            for(int j=0;j<=i;j++)
            {
                if(j&&dp[i-1][j-1]>0&&min(dp[i-1][j-1],b)-a>0)
                    dp[i][j]=max(dp[i][j],min(dp[i-1][j-1],b)-a+c);
                if(dp[i-1][j]>0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+c);
            }
        }
        int ans=0;
        for(int i=n;i>=0;i--)
            for(int j=n;j>=0;j--)
                if(dp[i][j]>0) ans=max(j,ans);
        printf("%d\n",ans);
    }
    return 0;
}
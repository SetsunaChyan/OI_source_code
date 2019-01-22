#include <cstdio>
#include <memory.h>

typedef long long ll;
const ll mod=998244353ll;
ll dp[2005];
int n,m,cnt[2005];

int main()
{
    scanf("%d%d",&n,&m);
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        int k,tmp;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&tmp);
            cnt[tmp]++;
        }
    }
    for(int i=1;i<=2000;i++)
        for(int j=m;j;j--)
            dp[j]=(dp[j]+dp[j-1]*cnt[i]%mod)%mod;
    printf("%lld",dp[m]);
    return 0;
}
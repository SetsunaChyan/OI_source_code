#include <cstdio>
#include <memory.h>

typedef long long ll;
ll a[100005],dp[100005],sum;
int n;

inline int min(int a,int b){return a<b?a:b;}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    scanf("%lld",&sum);
    dp[0]=0;
    for(int i=0;i<n;i++)
        for(int j=a[i];j<=sum;j++)
            dp[j]=min(dp[j],dp[j-a[i]]+1);
    printf("%lld",dp[sum]);
    return 0;
}
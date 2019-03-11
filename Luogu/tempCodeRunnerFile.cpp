#include <cstdio>
#include <memory.h>

int t,n,dp[100005],a[55],b[55],c[55],ans=0;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&t,&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
        for(int j=t;j>=c[i];j--)
            dp[j]=max(dp[j-c[i]]+a[i]-j*b[i],dp[j]);
    for(int i=0;i<=t;i++)
        ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}
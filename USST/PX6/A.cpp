#include <cstdio>
#include <memory.h>

int n,dp[1005],a[1005];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) dp[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j]>=a[i]) dp[i]=max(dp[i],dp[j]+1);
    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
    printf("%d ",ans);
    ans=0;
    for(int i=0;i<n;i++) dp[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}
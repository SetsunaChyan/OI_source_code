//unsolved

#include <cstdio>
#include <memory.h>

typedef long long ll;
int n,k,a[11];
struct node
{
    int t,val;
}dp[9*200050];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<k;i++)
        for(int j=a[i];j<=n/2;j++)
        {
            dp[i]=dp[i-j]+
        }
    return 0;
}
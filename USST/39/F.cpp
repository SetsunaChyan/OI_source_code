#include <cstdio>
#include <memory.h>
#include <cmath>

typedef long long ll;
ll dp[150],v[6]={2,3,4,5,6,7};
int n,ans;
double p=0;

int main()
{
    scanf("%d",&n);
    for(int t=1;t<=n/2;t++)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=t;i++)
            for(int j=7*t;j>=0;j--)
            {
                dp[j]=0;
                for(int k=0;k<6;k++)
                    if(v[k]<=j) dp[j]+=dp[j-v[k]];
            }
        double tmp=(double)dp[n]/pow(6,t);
        if(tmp>p)
        {
            ans=t;
            p=tmp;
        }
    }
    printf("%d",ans);
    return 0;
}
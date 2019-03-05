#include <cstdio>
#include <memory.h>

using namespace std;

const int v[6]={1,2,3,5,10,20};
int dp[10005],ans=0;

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<6;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
            for(int k=10000;k>=v[i];k--)
                dp[k]|=dp[k-v[i]];
    }
    for(int i=1;i<=10000;i++) ans+=dp[i];
    printf("%d",ans);
    return 0;
}
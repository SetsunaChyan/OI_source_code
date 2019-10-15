#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,n,m,rain[2005],umb[2005];
ll dp[2005];

int main()
{
    memset(umb,0x3f,sizeof(umb));
    memset(dp,0x3f,sizeof(dp));
    scanf("%d%d%d",&a,&n,&m);
    for(int i=0,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        for(int j=x+1;j<=y;j++) rain[j]=1;
    }
    for(int i=0,x,y;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        umb[x]=min(umb[x],y);
    }
    dp[0]=0;
    for(int i=1;i<=a;i++)
        if(rain[i])
        {
            for(int j=0;j<i;j++)
                if(umb[j]!=0x3f3f3f3f) dp[i]=min(dp[i],dp[j]+umb[j]*(i-j));
        }
        else
        {
            for(int j=i-1;j>=0;j--)
            {
                dp[i]=min(dp[i],dp[j]);
                if(rain[j]) break;
            }
        }
    if(dp[a]>=0x3f3f3f3f3f3f3f3fll)
    {
        printf("-1");
        return 0;
    }
    printf("%lld\n",dp[a]);
    return 0;
}

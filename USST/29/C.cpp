#include <cstdio>
#include <memory.h>

const int INF=0x3f3f3f3f;
int dp[1000005],a[1000005],m,n;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        {
            int mx,tmp,k=i&1;
            if(i) mx=dp[i-1]; else mx=0;
            for(int j=i;j<n;j++)
            {
                if(!j){dp[j]=a[j];continue;}
                tmp=max(dp[j],mx);
                dp[j]=a[j]+max(dp[j-1],mx);
                mx=tmp;
            }
        }
        int ans=-INF;
        for(int i=m-1;i<n;i++) ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
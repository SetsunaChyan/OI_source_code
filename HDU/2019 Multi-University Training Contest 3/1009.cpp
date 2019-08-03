#include <bits/stdc++.h>
using namespace std;
int n,k,a[2005],dp[2005],pre[2005];
bool h[2005];
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int ans=0,nn=n;
        while(k--)
        {
            if(nn<1)break;
            memset(h,0,sizeof(bool)*(nn+2));
            memset(dp,0,sizeof(int)*(nn+2));
            memset(pre,-1,sizeof(int)*(nn+2));
            int mai=1;
            dp[1]=a[1];
            for(int i=2;i<=nn;i++)
            {
                dp[i]=a[i];
                for(int j=i-1;j>=0;j--)
                    if(a[j]<=a[i]&&dp[i]<=dp[j]+a[i])
                    {
                        dp[i]=dp[j]+a[i];
                        if(dp[i]>dp[mai])
                            mai=i;
                        pre[i]=j;
                    }
            }
            ans+=dp[mai];
            while(mai!=-1)
                h[mai]=1,mai=pre[mai];
            int t=0;
            for(int i=1;i<=nn;i++)
                if(!h[i])
                    a[++t]=a[i];
            nn=t;
        }
        printf("%d\n",ans);
    }
    return 0;
}

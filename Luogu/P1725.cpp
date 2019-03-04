#include <cstdio>

int q[200000],a[200000],n,l,r,dp[200000];

int main()
{
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    dp[0]=a[0];
    for(int i=1;i<l;i++)
        dp[i]=0;
    int h=0,e=0;
    for(int i=l;i<n;i++)
    {
        while(h!=e&&dp[q[e-1]]<dp[i-l]) e--;
        q[e++]=i-l;
        if(q[h]<i-r) h++;
        dp[i]=dp[q[h]]+a[i];
    }
    int maxn=dp[n-r];
    for(int i=n-r+1;i<n;i++)
        if(dp[i]>maxn) maxn=dp[i];
    printf("%d\n",maxn);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ans,a[2][300005],suf00[300005],suf11[300005],suf0[300005],suf1[300005];


int main()
{
    scanf("%d",&n);
    for(int i=0;i<=1;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
    for(int i=n;i>=1;i--)
    {
        suf00[i]=suf00[i+1]+a[0][i]+a[1][i];
        suf11[i]=suf11[i+1]+a[0][i]+a[1][i];
    }
    for(int i=n;i>=1;i--)
    {
        suf0[i]=suf0[i+1]+(i-1)*a[0][i]+(2*n-i)*a[1][i];
        suf1[i]=suf1[i+1]+(i-1)*a[1][i]+(2*n-i)*a[0][i];
    }
    ll now=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        printf("suf0 %lld    suf1 %lld\n",suf0[i],suf1[i]);
        ans=max(ans,sum+((i&1)?suf0[i]:suf1[i]));
        if(i&1)
            sum+=now*a[0][i],sum+=(now+1)*a[1][i];
        else
            sum+=now*a[1][i],sum+=(now+1)*a[0][i];
        now+=2;
    }
    printf("%lld",ans);
    return 0;
}

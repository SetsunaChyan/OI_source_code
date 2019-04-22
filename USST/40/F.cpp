#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[300005],pre[300005][2],sum=0,t=0;
ll ans=0,x;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        a[i]=__builtin_popcountll(x);
        sum+=a[i];
    }
    pre[n][0]=1,pre[n][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        t+=a[i];
        pre[i][0]=pre[i+1][0]+(~t&1);
        pre[i][1]=pre[i+1][1]+(t&1);
    }
    for(int i=0;i<n;i++)
    {
        int dlt=pre[i+1][sum&1],tmp=0,ma=0;
        sum-=a[i];
        for(int j=0;j<=64&&i+j<n;j++)
        {
            tmp+=a[i+j];
            ma=max(ma,a[i+j]);
            if(tmp%2==0&&tmp-ma<ma) dlt--;
        }
        ans+=dlt;
    }
    printf("%lld",ans);
    return 0;
}
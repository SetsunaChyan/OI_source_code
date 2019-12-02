#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,x,d,ans,dp[1<<15];
ll a[20];
set<int> s;

int main()
{
    scanf("%d%d%d",&n,&x,&d);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    for(int i=1;i<(1<<n);i++)
    {
        ll sum=0,mm=0x3f3f3f3f,mx=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                mm=min(mm,a[j]),mx=max(mx,a[j]),sum+=a[j];
        if(sum>=x&&mx-mm<=d) ans++;//s.insert(i);
    }
    /*for(int i=1;i<(1<<n);i++)
        for(int j=i;j;j=(j-1)&i)
        {
            dp[i]=max(dp[i],dp[i-j]);
            if(s.count(j)) dp[i]=max(dp[i],dp[i-j]+1);
            ans=max(ans,dp[i]);
        }*/
    printf("%d",ans);
    return 0;
}

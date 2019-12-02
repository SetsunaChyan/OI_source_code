#include <bits/stdc++.h>
using namespace std;

int n,k,dp[100005],a[100005];

int gao(int x)
{
    int cnt=0;
    while(x%2==0)
        cnt++,x>>=1;
    return cnt;
}

void solve()
{
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        int t=0;
        for(int j=0;j<i;j++)
            if(a[j]<a[i]) t=max(t,dp[j]);
        ans=max(ans,dp[i]=t+gao(a[i]));
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

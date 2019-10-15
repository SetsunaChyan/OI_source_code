#include <bits/stdc++.h>
using namespace std;

int n,a[200005],dp[200005],ans[200005],last[10],mx;

void solve()
{
    memset(last,0,sizeof(last));
    mx=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%1d",&a[i]),dp[i]=0,ans[i]=1;
    for(int i=n;i>=1;i--)
    {
        dp[i]=1;
        for(int j=0;j<a[i];j++)
            dp[i]=max(dp[i],last[j]+1);
        last[a[i]]=dp[i];
        mx=max(mx,dp[i]);
    }
    if(mx==1)
    {
        for(int i=1;i<=n;i++) printf("1");
        printf("\n");
        return;
    }
    if(mx>2)
    {
        printf("-\n");
        return;
    }
    int j,i,l;
    for(i=1;i<=n;i++)
        if(dp[i]==2) break;
    l=a[i];
    for(int j=i;j<=n;j++)
        if(a[j]>=l) ans[j]=2,l=a[j];
    for(int i=1;i<=n;i++)
        if(!ans[i]) ans[i]=1;
    for(int i=1;i<=n;i++) printf("%d",ans[i]);
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}


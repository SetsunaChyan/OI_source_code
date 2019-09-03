#include <bits/stdc++.h>
using namespace std;

int n,k,ans,a[100],b[100],dp[100],jc[100];

void buu()
{
    for(int i=0;i<n;i++)
        a[i]=b[i];
    for(int i=0;i<k;i++)
        for(int j=1;j<n;j++)
            if(a[j-1]>a[j]) swap(a[j-1],a[j]);
}

bool check()
{
    int mx=0;
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
    for(int i=1;i<n;i++)
        mx=max(mx,dp[i]);
    if(mx>=n-1) return true;
    //for(int i=0;i<n;i++)
    //    printf("%d ",a[i]);
    //printf("\n");
    return false;
}

void solve()
{
    ans=0;
    for(int i=0;i<n;i++) b[i]=i+1;
    do
    {
        buu();
        if(check()) ans++;
    }while(next_permutation(b,b+n));
    printf("%d %d\n",ans,jc[n]/jc[n-k]*(1+(n-k-1)*(n-k)/2));
}

int main()
{
    jc[0]=1;
    for(int i=1;i<=10;i++) jc[i]=jc[i-1]*i;
    while(~scanf("%d%d",&n,&k)) solve();
    return 0;
}

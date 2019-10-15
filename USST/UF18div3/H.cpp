#include <bits/stdc++.h>
using namespace std;

int n,bit[100005],dp[100005],a[100005],ans;

int query(int x)
{
	int ret=0;
	for(;x; x-=x&-x) ret=max(ret,bit[x]);
	return ret;
}

void modify(int x,int y)
{
	for(;x<=n;x+=x&-x) bit[x]=max(y,bit[x]);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        dp[i]=query(a[i])+1;
		modify(a[i],dp[i]);
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}

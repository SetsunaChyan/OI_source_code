#include <bits/stdc++.h>
using namespace std;

int n,dp[1000005],cost[10]={6,2,5,5,4,5,6,3,7,6};

int main()
{
	freopen("auxiliary.in","r",stdin);
	freopen("auxiliary.out","w",stdout);
	scanf("%d",&n);
	memset(dp,0xc0,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=9;j++)
			if(i-cost[j]>=0) dp[i]=max(dp[i],dp[i-cost[j]]+j);
	//for(int i=1;i<=n;i++) printf("! %d \n",dp[i]);
	printf("%d",dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#define sd(a) cin>>a
using namespace std;

int dp[200001][15];
int main()
{
	//freopen("5.in","r",stdin);
	int n;
	int x,t;
	while(cin>>n&&n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i)
		{
			sd(x);sd(t);
			dp[t][x]++;
		}
		for(int i=100000;i>=0;--i)
			for(int j=0;j<=10;++j)
				dp[i][j]+=max(dp[i+1][j],max(dp[i+1][max(j-1,0)],dp[i+1][j+1]));
		cout<<dp[0][5]<<endl;
	}
	return 0;
}
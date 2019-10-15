#include <bits/stdc++.h>
using namespace std;

const int MOD =1e9+7;
int len,n,fail[200],dp[201][202][201];
char s[201];

void make_fail()
{
	char temp[201];
	for(int i=0;i<len;i++)
	{
		int cnt=0;
		for(int j=0;j<i;j++)
			temp[j]=s[j];
		if(s[i]==')') temp[i]='('; else temp[i]=')';
		temp[i+1]=0;
		for(int j=1;j<=i;j++)
		{
			int flag=0;
			for(int k=0;k<j;k++)
				if(s[k]!=temp[k-j+i+1])
				{
					flag=1;
					break;
				}
			if(flag==0) cnt=j;
		}
		fail[i]=cnt;
	}
}

int main()
{
	scanf("%d%s",&n,s);
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	len=strlen(s);
	make_fail();
	for(int i=0;i<2*n;i++)
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<len;k++)
			{
				if(s[k]=='(')
				{
					dp[i+1][j+1][k+1]=(dp[i+1][j+1][k+1]+dp[i][j][k])%MOD;
					if(j!=0) dp[i+1][j-1][fail[k]]=(dp[i+1][j-1][fail[k]]+dp[i][j][k])%MOD;
				}
				else
				{
					if(j!=0) dp[i+1][j-1][k+1]=(dp[i+1][j-1][k+1]+dp[i][j][k])%MOD;
					dp[i+1][j+1][fail[k]]=(dp[i+1][j+1][fail[k]]+dp[i][j][k])%MOD;
				}
			}
			dp[i+1][j+1][len]=(dp[i+1][j+1][len]+dp[i][j][len])%MOD;
			if(j!=0) dp[i+1][j-1][len]=(dp[i+1][j-1][len]+dp[i][j][len]) % MOD;
		}
	printf("%d\n",dp[2*n][0][len]);
	return 0;
}

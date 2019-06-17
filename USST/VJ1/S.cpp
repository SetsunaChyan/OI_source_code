#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,f[21],c[21][21];

int main()
{
	int _,t;
	c[0][0]=1,f[0]=f[1]=1;
	for(int i=1;i<=20;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	for(int i=2;i<=20;i++)
	{
		f[i]=0;
		for(int j=0;j<i;j++)
			f[i]+=c[i-1][j]*f[j]*f[i-1-j];
		f[i]>>=1;
	}
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d%lld",&t,&n);
		printf("%d %lld\n",t,n==1?1ll:f[n]<<1);
	}
    return 0;
}
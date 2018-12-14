#include <cstdio>
#include <memory.h>

typedef long long ll;

int n,t;
ll f[21][121];

ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}

int main()
{
	ll temp=0,fm=1;
	scanf("%d%d",&n,&t);
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=6;j++)
			for(int k=j;k<=120;k++) //if(f[i-1][k-j])
				f[i][k]+=f[i-1][k-j];
	for(int k=t;k<=120;k++)
		temp+=f[n][k];
	for(int i=0;i<n;i++) fm*=6;
	int ys=gcd(fm,temp);
	fm/=ys;
	temp/=ys;
	if(temp==1&&fm==1)
		printf("1");
	else if(temp==0)
		printf("0");
	else
		printf("%lld/%lld",temp,fm);
	return 0;
}
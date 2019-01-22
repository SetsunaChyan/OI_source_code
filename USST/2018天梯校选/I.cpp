#include <cstdio>
#include <memory.h>

typedef long long ll;
const ll mod=99999;
ll c[1005][1005],f[1005];
int n;

int main()
{
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	f[0]=1;
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i]=(f[i]+f[j-1]*c[n-j+1][i-j+1])%mod;
	printf("%lld",f[n]);
	return 0;
}
#include <cstdio>
#include <memory.h>
typedef long long ll;

int n;
ll f[60][4];

int main()
{
	memset(f,0,sizeof(f));
	f[0][3]=1;
	for(int i=1;i<55;i++)
	{
		f[i][3]=f[i-1][2]+f[i-1][3];
		f[i][2]=f[i-1][1];
		f[i][1]=f[i-1][0];
		f[i][0]=f[i][3];
	}
	while(~scanf("%d",&n)&&n)
	{
		n--;
		printf("%lld\n",f[n][0]+f[n][1]+f[n][2]+f[n][3]);
	}
	return 0;
}

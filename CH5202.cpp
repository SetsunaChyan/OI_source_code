#include <cstdio>
#include <memory.h>

typedef long long ll;
int n;
ll f[4001];

void cpack(int w)
{
	for(int i=w;i<=n;i++)
		f[i]=(f[i]+f[i-w])%2147483648ll;
}

int main()
{
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++)
		cpack(i);
	printf("%lld",f[n]>0?f[n]-1:2147483647ll);
	return 0;
}
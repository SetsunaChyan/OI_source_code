#include <cstdio>
#include <memory.h>

long long g[151];

long long f(int x)
{
	if(x<=1) return 0;
	if(~g[x]) return g[x];
	return g[x]=f(x-2)+f(x-3);
}

int main()
{
	memset(g,-1,sizeof(g));
	g[2]=g[3]=1;
	int n;
	scanf("%d",&n);
	printf("%lld",f(n));
	return 0;
}
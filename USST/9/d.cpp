#include <cstdio>
#include <memory.h>

int n;
long long f[31];

long long g(int x)
{
	if(f[x]) return f[x];
	for(int i=0;i<x;i++)
		f[x]+=g(i)*g(x-i-1);
	return f[x];
}

int main()
{
	memset(f,0,sizeof(f));
	f[0]=1;
	scanf("%d",&n);
	printf("%lld %d",g(n),n+1);
	return 0;
}
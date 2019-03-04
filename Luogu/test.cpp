#include <cstdio>
#include <time.h>

const long long MAXN=1e8;

int main()
{
	long long a=0;
	for(long long i=0;i<MAXN;i++)
		a++;
	printf("%lld\n",a);
	printf("runtime : %.0lfms",(double)clock()/CLOCKS_PER_SEC*1000);
	return 0;
}
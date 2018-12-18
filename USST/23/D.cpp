#include <cstdio>

int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		long long p=1;
		for(int i=0;i<n-1;i++)
			p=(p+1)*2;
		printf("%lld\n",p);
	}
	return 0;
}

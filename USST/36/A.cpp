#include <cstdio>
int n;

int main()
{
	scanf("%d",&n);
	long long ans=0;
	for(int i=0;i<2*n-1;i++)
	{
		long long x;
		scanf("%lld",&x);
		ans^=x;
	}
	printf("%lld",ans);
	return 0;
}

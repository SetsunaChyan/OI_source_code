#include <cstdio>

int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=30;i>0;i--)
	{
		int k=1<<i;
		while(n>=k)
		{
			n-=k;
			ans+=k-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
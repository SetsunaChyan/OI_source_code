#include <cstdio>

int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k=i;
		while(!(k&1)) k>>=1;
		ans+=k;
	}
	printf("%lld",ans);
	return 0;
}
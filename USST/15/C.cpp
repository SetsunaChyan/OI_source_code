#include <cstdio>

int n;
long long ans=0;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>0) ans+=x; else ans-=x;
	}
	printf("%lld",ans);
	return 0;
}
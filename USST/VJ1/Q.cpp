#include <cstdio>
typedef long long ll;

int main()
{
	int _,n;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);
		printf("%lld\n",2ll*n*n-n+1);
	}
	return 0;
}

#include <cstdio>

const long long inv24=41666667;
const long long mod=1e9+7;

int main()
{
	int _;
	long long k;
	scanf("%d",&_);
	while(_--&&~scanf("%lld",&k))
		printf("%lld\n",k*(k+1)%mod*(k+2)%mod*(k+3)%mod*inv24%mod);
	return 0;
}
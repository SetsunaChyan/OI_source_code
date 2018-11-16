#include <cstdio>

typedef long long ll;
ll a,b,p;

ll fp()
{
	ll ret=1,k=a;
	while(b)
	{
		if(b&1) ret=ret*k%p;
		b>>=1;
		k=k*k%p;
	}
	return ret%p;
}

int main()
{
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld",fp());
	return 0;
}
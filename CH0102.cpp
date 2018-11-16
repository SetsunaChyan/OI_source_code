#include <cstdio>

typedef long long ll;
ll a,b,p;

ll f()
{
	ll ret=0,k=a%p;
	while(b)
	{
		if(b&1)
			ret=(ret+k)%p;
		k=(k*2)%p;
		b>>=1;
	}
	return ret;
}

int main()
{
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld",f());
	return 0;
}
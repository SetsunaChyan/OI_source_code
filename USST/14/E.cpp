#include <cstdio>

typedef long long ll;
ll ans,n;

ll f(ll x)
{
	if(x==0) return 0;
	if(x&1) return x+f(x-1);
	return x/2*x/2+f(x/2);
}
int main()
{
	scanf("%lld",&n);
	printf("%lld",f(n));
	return 0;
}
#include <cstdio>

typedef long long ll;
ll n,m,mod;

ll fp(ll a,ll b)
{
	ll ans=1,p=a;
	while(b)
	{
		if(b&1) ans=ans*p%mod;
		p=p*p%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&mod);
	printf("%lld^%lld mod %lld=%lld\n",n,m,mod,fp(n,m)%mod);
	return 0;
}
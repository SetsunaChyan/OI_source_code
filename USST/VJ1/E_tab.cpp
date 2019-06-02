#include <cstdio>

typedef long long ll;

bool ok(ll x)
{
	while(x)
	{
		if(x%10>1) return false;
		x/=10;
	}
	return true;
}

int main()
{
	freopen("2.out","w",stdout);
	for(ll i=1;i<=200;i++)
		for(ll j=1;j*i<=(1ll<<60);j++)
			if(ok(i*j)) {printf("%lldll,",i*j);break;}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll phi(ll x)
{
    ll ret=x;
    for(ll i=2;i*i<=x;++i)
		if(x%i==0)
		{
	        ret=ret*(i-1)/i;
	        while(x%i==0)
				x/=i;
    	}
    if(x!=1)
		ret=ret*(x-1)/x;
    return ret;
}
ll qpow(ll a,ll b,ll mod)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)
			ans=ans*a%mod;
	return ans;
}

int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		ll a,b,mod,p,pp;
		scanf("%lld%lld%lld",&a,&b,&mod);
		p=phi(mod);
		pp=phi(p);
		if(b==0){printf("1\n");continue;}
		else if(b==1){printf("%lld\n",a%mod);continue;}
		else if(b==2){printf("%lld\n",qpow(a,a,mod));continue;}
		b-=2;
		ll ans=qpow(a,qpow(a,qpow(a,b,pp)+pp,p)+p,mod);
		printf("aqa %lld\n",qpow(2,1%phi(100000)+phi(100000),100000));
		printf("qaq %lld %lld\n",p,pp);
		printf("%lld %.0f\n",ans,pow(a,pow(a,pow(a,b))));
	}
	return 0;
}

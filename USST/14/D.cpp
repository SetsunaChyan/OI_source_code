#include <cstdio>

typedef long long ll;
ll x,y,n;

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
	ll ans=(ll)(1<<31)-1;
	ans*=ans;
	ll lay=2;
	scanf("%lld%lld%lld",&n,&x,&y);
	for(int i=2;i<=n;i++)
	{
		ll b=n-i,c=i-2;
		for(int j=0;j<=c;j++)
		{
			ll a=c-j;
			if(ans>(b*(b+1)/2)*x+(a*(a+1)/2)*y+j*(j+1)/2*x)
			{
				lay=i;
				ans=(b*(b+1)/2)*x+(a*(a+1)/2)*y+j*(j+1)/2*x;
			}
		}
	}
	printf("%lld %lld",lay,ans);
	return 0;
}
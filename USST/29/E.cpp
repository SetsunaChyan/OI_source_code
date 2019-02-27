#include <cstdio>

typedef long long ll;
int n;
ll x,ans=0;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&x);
		if(x<0) ans+=(i+1)*x; else ans+=x;
	}	
	printf("%lld",ans);
	return 0;
}
#include <cstdio>
#include <cmath>

typedef long long ll;
ll n,a,b,c;

int main()
{
	while(~scanf("%lld%lld",&a,&n))
	{
		if(n==0||n>2) {printf("-1 -1\n"); continue;}
		if(n==1)
		{
			printf("1 %lld\n",a+1);
			continue;
		}
		if(a&1)
		{
			b=(a*a-1)/2;
			c=round(sqrt(b*b+a*a));
		}
		else
		{
			b=(a/2)*(a/2)-1;
			c=round(sqrt(b*b+a*a));
		}
		printf("%lld %lld\n",b,c);
	}
	return 0;
}
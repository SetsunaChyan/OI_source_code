#include <cstdio>

int main()
{
	long long a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long ans=0;
	ans+=(b/2-(a-1)/2)*(d/1009-(c-1)/1009);
	ans+=(d/2-(c-1)/2)*(b/1009-(a-1)/1009);
	ans+=(b-a+1)*(d/2018-(c-1)/2018);
	ans+=(d-c+1)*(b/2018-(a-1)/2018);
	ans-=(b/2-(a-1)/2)*(d/2018-(c-1)/2018);
	ans-=(b/2018-(a-1)/2018)*(d/2-(c-1)/2);
	ans-=(b/2018-(a-1)/2018)*(d/1009-(c-1)/1009);
	ans-=(b/1009-(a-1)/1009)*(d/2018-(c-1)/2018);
	ans+=(d/2018-(c-1)/2018)*(b/2018-(a-1)/2018);
	printf("%lld",ans);	
	return 0;
}
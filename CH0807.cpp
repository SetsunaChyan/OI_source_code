#include <cstdio>
#include <algorithm>

int n;
long long s[1000005],sum=0,t;

inline long long abs(long long x){return x<0?-x:x;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
		sum+=s[i];
	}
	sum/=n;
	s[0]-=sum;
	for(int i=1;i<n;i++)
		s[i]+=s[i-1]-sum;
	std::sort(s,s+n);
	t=s[n/2],sum=0;
	for(int i=0;i<n;i++)
		sum+=abs(s[i]-t);
	printf("%lld",sum);
	return 0;
}
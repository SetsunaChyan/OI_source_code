#include <cstdio>
#include <algorithm>

int a[100005],t;
long long ans=0;

inline long long abs(long long x){return x<0?-x:x;}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	std::sort(a,a+n);
	t=a[n/2];
	for(int i=0;i<n;i++)
		ans+=abs((long long)t-a[i]);
	printf("%lld",ans);	
	return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

long long c[1000005],tot,ans,x1;
int n;

int main()
{
	while(~scanf("%d",&n))
	{
		tot=0;
		c[0]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			long long x;
			scanf("%lld",&x);
			c[i]=c[i-1]+x;
			tot+=x;
		}
		tot/=n;
		for(int i=1;i<=n;i++) c[i]=i*tot-c[i];
		sort(c,c+n);
		x1=c[n/2];
		for(int i=0;i<n;i++) ans+=x1-c[i]<0?c[i]-x1:x1-c[i];
		printf("%lld\n",ans);
	}
	return 0;
}
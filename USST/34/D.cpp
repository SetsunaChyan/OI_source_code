#include <cstdio>

typedef long long ll;
ll a[300005],dif[300005],now,ans=-0x3f3f3f3f;
int n;

inline ll abs(ll x){if(x<0) return -x; else return x;}
inline ll max(ll a,ll b){return a>b?a:b;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<n-1;i++)
		dif[i]=abs(a[i+1]-a[i]);
	for(int i=1;i<n-1;i+=2)
		dif[i]=-dif[i];
	now=0;
	for(int i=0;i<n;i++)
	{
		now+=dif[i];
		if(now<0) now=0;
		ans=max(ans,now);
	}	
	for(int i=0;i<n-1;i++)
		dif[i]=-dif[i];
	now=0;
	for(int i=0;i<n;i++)
	{
		now+=dif[i];
		if(now<0) now=0;
		ans=max(ans,now);
	}	
	printf("%lld",ans);
	return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=5050;
ll f[MAXN],a[MAXN],d[MAXN];
int n;

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		d[i]=a[i];
	}
	sort(d,d+n);
	for(int i=0;i<n;i++) f[i]=abs(a[0]-d[i]);
	for(int i=1;i<n;i++)
	{
		ll val=f[0];
		for(int j=0;j<n;j++)
		{
			val=min(val,f[j]);
			f[j]=val+abs(a[i]-d[j]);
		}
	}
	ll ans=f[0];
	for(int i=1;i<n;i++)
		ans=min(ans,f[i]);
	printf("%I64d",ans);
	return 0;
}
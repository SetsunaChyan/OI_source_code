#include <cstdio>
#include <memory.h>

typedef long long ll;
const int MAXN=3840;
ll ans=0,d[MAXN][2],u[MAXN];
int n,b;

inline ll max(ll a,ll b){return a>b?a:b;}

inline void dp()
{
	for(int i=1;i<n;i++)
		for(int j=b;j>=1;j--)
		{
			d[j][0]=max(d[j][0],d[j][1]);
			d[j][1]=max(d[j-1][1]+u[i],d[j-1][0]);
		}
}

int main()
{
	memset(d,0xc0,sizeof(d));
	scanf("%d%d",&n,&b);
	for(int i=0;i<n;i++)
		scanf("%lld",&u[i]);
	d[0][0]=d[1][1]=0;
	dp();
	ll ans=max(d[b][0],d[b][1]);
	memset(d,0xc0,sizeof(d));
	d[0][0]=0;
	d[1][1]=u[0];
	dp();
	printf("%lld",max(ans,d[b][1]));
	return 0;
}
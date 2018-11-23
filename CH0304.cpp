#include <cstdio>

typedef long long ll;
int n;
ll a[2],pos=0,neg=0;

inline ll max(ll a,ll b){return a>b?a:b;}
inline ll abs(ll x){return x<0?-x:x;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i&1]);
		if(i)
		{
			if(a[i&1]-a[i&1^1]>0)
				pos+=a[i&1]-a[i&1^1];
			else
				neg-=a[i&1]-a[i&1^1];
		}
	}
	printf("%lld\n%lld",max(pos,neg),abs(pos-neg)+1);
	return 0;
}
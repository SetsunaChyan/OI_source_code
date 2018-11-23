#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD=9901;
int a,b;
vector<pair<int,int> > v;
ll ans=1;

void fj()
{
	v.clear();
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			int k=0;
			while(a%i==0){k++;a/=i;}
			v.push_back(make_pair(i,k*b));
		}
	}
	if(a>1) v.push_back(make_pair(a,b));
}

ll fast_power(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll cal(ll x,ll y)
{
	if(y==1) return (1+x)%MOD;
	if(y==0) return 1;
	if(y&1) return cal(x,(y-1)/2)*(1+fast_power(x,(y+1)/2))%MOD;
	return (cal(x,y/2-1)*(1+fast_power(x,y/2))+fast_power(x,y))%MOD;
}

int main()
{
	scanf("%d%d",&a,&b);
	fj();
	int l=v.size();
	for(int i=0;i<l;i++)
	{
		int k=v[i].second,x=v[i].first;
		ans=(ans*cal(x,k))%MOD;
	}
	printf("%lld",ans);
	return 0;
}
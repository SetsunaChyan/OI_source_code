#include <cstdio>
#include <memory.h>
#include <algorithm>

typedef long long ll;
const int MAXN=5e5+50;
struct node
{
	int v,pos;
}e[MAXN];
ll bit[MAXN],a[MAXN];
int n;

inline bool cmp(node a,node b){return a.v<b.v;}
inline int lowbit(int x){return x&-x;}

void dis()
{
	int cnt=0;
	std::sort(e,e+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(!i||e[i].v!=e[i-1].v) cnt++;
		a[e[i].pos]=cnt;
	}
}

inline void add(int x,ll y)
{
	for(;x<=n;x+=lowbit(x)) bit[x]+=y;
}

inline ll sum(int x)
{
	ll ret=0;
	for(;x>0;x-=lowbit(x)) ret+=bit[x];
	return ret;
}

int main()
{
	while(~scanf("%d",&n)&&n)
	{
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&e[i].v);
			e[i].pos=i;
		}
		dis();
		memset(bit,0,sizeof(bit));
		for(int i=n-1;i>=0;i--)
		{
			add(a[i],1);
			ans+=sum(a[i]-1);
		}
		printf("%lld\n",ans);
	}

	return 0;
}
#include <cstdio>
#include <memory.h>

const int MAXN=100005;
long long BIT[MAXN],n,pre[MAXN],suf[MAXN],a[MAXN];

void add(int x,int y)
{
	for(;x<=100000;x+=x&-x) BIT[x]+=y;
}

long long sum(int x)
{
	long long ret=0;
	for(;x>0;x-=x&-x) ret+=BIT[x];
	return ret;
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		long long ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		memset(BIT,0,sizeof(BIT));
		for(int i=1;i<=n;i++)
		{
			add(a[i],1);
			pre[i]=sum(a[i]-1);
		}
		memset(BIT,0,sizeof(BIT));
		for(int i=n;i>=1;i--)
		{
			add(a[i],1);
			suf[i]=sum(a[i]-1);
		}
		for(int i=2;i<=n-1;i++)
			ans+=pre[i]*(n-i-suf[i])+suf[i]*(i-1-pre[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
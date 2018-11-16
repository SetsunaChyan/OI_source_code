#include <cstdio>
#include <memory.h>

typedef long long ll;
ll BIT1[100050],BIT2[100050];
int n,m;

inline ll lowbit(ll x)
{
	return x&-x;
}

void add(ll BIT[],int x,ll y)
{
	for(;x<=n;x+=lowbit(x)) BIT[x]+=y;
}

ll sum(ll BIT[],int x)
{
	ll ret=0;
	for(;x>0;x-=lowbit(x)) ret+=BIT[x];
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(BIT1,0,sizeof(BIT1));
	memset(BIT2,0,sizeof(BIT2));
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		add(BIT1,i,x);
		add(BIT1,i+1,-x);
		add(BIT2,i,i*x);
		add(BIT2,i+1,-(i+1)*x);
	}
	while(m--)
	{
		char c;
		int l,r;
		scanf(" %c%d%d",&c,&l,&r);
		if(c=='Q')
		{
			ll s1=sum(BIT1,r)*(r+1)-sum(BIT2,r),s2=sum(BIT1,l-1)*l-sum(BIT2,l-1);
			printf("%lld\n",s1-s2);
		}
		else
		{
			ll k;
			scanf("%lld",&k);
			add(BIT1,l,k);
			add(BIT1,r+1,-k);
			add(BIT2,l,l*k);
			add(BIT2,r+1,-(r+1)*k);
		}
	}
	return 0;
}
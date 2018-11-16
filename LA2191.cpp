#include <cstdio>
#include <memory.h>

const int MAXN=2e5+50;
int n,BIT[MAXN],a[MAXN];

inline int lowbit(int x)
{
	return x&-x;
}

void add(int x,int y)
{
	for(;x<=n;x+=lowbit(x)) BIT[x]+=y;
}

long long sum(int x)
{
	long long ret=0;
	for(;x>0;x-=lowbit(x)) ret+=BIT[x];
	return ret;
}

int main()
{
	int t=0;
	while(scanf("%d",&n)&&n)
	{
		if(t) printf("\n");
		t++;
		printf("Case %d:\n",t);
		memset(BIT,0,sizeof(BIT));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			add(i,a[i]);
		}
		char opt[10];
		int x,y;
		while(scanf("%s",opt))
		{
			if(opt[0]=='E') break;
			scanf("%d%d",&x,&y);
			if(opt[0]=='S')
			{
				add(x,y-a[x]);
				a[x]=y;
			}
			else
				printf("%lld\n",sum(y)-sum(x-1));
		}
	}
	return 0;
}
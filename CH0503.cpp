#include <cstdio>
#include <memory.h>

const int MAXN=505;
int bit[MAXN*MAXN],n;

inline int lowbit(int x){return x&-x;}
inline int abs(int x){return x<0?-x:x;}
inline void add(int x){for(;x<=n*n;x+=lowbit(x)) bit[x]++;}

inline int sum(int x)
{
	int ret=0;
	for(;x>0;x-=lowbit(x)) ret+=bit[x];
	return ret;
}

int get()
{
	int ret=0;
	memset(bit,0,sizeof(bit));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int x;
			scanf("%d",&x);
			if(!x) continue;
			add(x);
			ret+=sum(x-1);
		}
	return ret;
}

int main()
{
	while(~scanf("%d",&n))
	{
		int a=get(),b=get();
		if(abs(a-b)&1) 
			printf("NIE\n");
		else
			printf("TAK\n");
	}

	return 0;
}
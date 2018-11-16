#include <cstdio>

inline int fp(int a,int b,int p)
{
	int ret=1,k=a%p;
	while(b)
	{
		if(b&1) ret=ret*k%p;
		k=k*k%p;
		b>>=1;
	}
	return ret;
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		int p,n,ans=0;
		scanf("%d%d",&p,&n);
		while(n--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			ans=(ans+fp(x,y,p))%p;
		}
		printf("%d\n",ans);
	}
	return 0;
}
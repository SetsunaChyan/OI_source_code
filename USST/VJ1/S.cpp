#include <cstdio>
#include <memory.h>
typedef long long ll;

ll f[30];

int main()
{
	int _,n,t;
	scanf("%d",&_);
	ll p=1;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=20;i++)
		p*=i-1,f[i]=f[i-1]*i-p;
	while(_--)
	{
		scanf("%d%d",&t,&n);
		printf("%d %lld\n",t,f[n]);
	}
	
	return 0;
}

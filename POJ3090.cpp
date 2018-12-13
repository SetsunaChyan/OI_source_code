#include <cstdio>
#include <memory.h>

int phi[1001];

int main()
{
	int _;
	scanf("%d",&_);
	phi[1]=0;
	for(int i=2;i<=1000;i++) phi[i]=i;
	for(int i=2;i<=1000;i++)
		if(phi[i]==i)
			for(int j=i;j<=1000;j+=i)
				phi[j]=phi[j]/i*(i-1);
	for(int i=2;i<=1000;i++)
		phi[i]+=phi[i-1];
	for(int tcase=1;tcase<=_;tcase++)
	{
		int x;
		scanf("%d",&x);
		printf("%d %d %d\n",tcase,x,2*phi[x]+3);
	}	
	return 0;
}
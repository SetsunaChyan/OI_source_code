#include <stdio.h>
#include <math.h>

int n,m;

bool prime(int x)
{
	int i;
	if(x==1) return false;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0) return false;
	return true;
}

int main()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		if(prime(x)) printf("Yes\n"); else printf("No\n");
	}
	return 0;
} 

#include <cstdio>

int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}

int main()
{
	int a,b,n;
	scanf("%d%d%d",&n,&a,&b);
	int k=gcd(a,b),s=n/k-2;
	if(s&1)
		printf("vito");
	else
		printf("sorahjy");
	return 0;
}
#include <stdio.h>

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int i,j,ans=0,x,y;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
	{
		if(x*y%i!=0) continue;
		j=x*y/i;
		if(gcd(i,j)==x) ans++;
	}
	printf("%d",ans);
	return 0;
} 

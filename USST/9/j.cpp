#include <cstdio>

int gcd(int a,int b)
{
	return b==0?b:gcd(a,a%b);
}

int main()
{
	int t=0,x,y;
	while(~scanf("%d%d",&x,&y))
	{
		if(t) printf("\n\n");
		printf("%10d%10d    ",x,y);
		if(gcd(x,y)==1)
			printf("Good Choice");
		else
			printf("Bad Choice");
		t++;
	}
	return 0;
}
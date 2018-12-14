#include <cstdio>

int main()
{
	int sum=0,j=0;
	for(int i=2;i<=300;i+=2)
		if(i%7==0||i%17==0)
		{
			j++;
			printf("%6d",i);
			sum+=i;
			if(j%5==0) printf("\n");
		}
	printf("\nsum=%d",sum);
	return 0;
}
#include <stdio.h>

int main()
{
	int m,i,j=1,sum=0;
	scanf("%d",&m);
	for(i=1;i<m;i++)
	{
		sum+=i;
		if(sum<m) continue;
		while(sum>m) 
		{
			sum-=j;
			j++;
		}
		if(sum==m) printf("%d %d\n",j,i);
	}
	return 0;
}

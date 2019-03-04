#include <stdio.h>


int main()
{
	int i=1,j=1,tim,t=1,dir=-1;
	scanf("%d",&tim); 
	while(1)
	{
		if(dir==1)
		{
			if(j==1)
			{
				i++;
				dir=-dir;
			}
			else
			{
				i++;j--;
			}
		}
		else
		{
			if(i==1)
			{
				j++;
				dir=-dir;
			}
			else
			{
				i--;j++;
			}
		}
		t++;
		if(t==tim) break;
	}
	printf("%d/%d",i,j);
	return 0;
} 

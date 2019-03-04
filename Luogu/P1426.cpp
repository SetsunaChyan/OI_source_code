#include <stdio.h>

int main()
{
	int s,x;
	double speed=7;
	scanf("%d %d",&s,&x);
	while(1)
	{
		if(s<=x)
		{
			if(s-speed<-x)
			{
				printf("n");
				break;
			}
			else
			{
				printf("y");
				break;
			}
		}
		if(s-speed<=x)
		{
			s-=speed;
			speed*=0.98;
			if(s-speed<-x)
			{
				printf("n");
				break;
			}
			else
			{
				printf("y");
				break;
			}
		}
		s-=speed;
		speed*=0.98;
	}
	return 0;
}

#include <cstdio>
#include <stdlib.h>
#include <time.h>

const int T=10; 
const int L=10000;

int main()
{
	freopen("data.in","w",stdout);
	srand(time(0));
	for(int t=0;t<T;t++)
	{
		printf("%d %d %d\n",L,rand()%500,rand()%500);
		//for(int i=0;i<L;i++)
		//{
			//int a=rand()%1000,b=rand()%1000,c=rand()%100;
			//printf("%d %d %d\n",a,b,rand()%100);
		//}
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				printf("%d %d %d\n",i,j,rand()%100);
	} 
	return 0;
}
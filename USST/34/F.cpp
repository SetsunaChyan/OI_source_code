#include <cstdio>

int n,a[12],fa=0,sum=0,flag=0;

int main()
{
	scanf("%d",&n);n++;
	for(int g=0;g<n;g++)
	{
		scanf("%d",&a[g]);
		if(g&&a[g]!=1&&a[g-1]!=1) flag=1;
	}	
	if(!flag)
		printf("yes");
	else
	{
		printf("no\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<a[i];j++)
			{
				sum++;
				printf("%d ",fa);
			}
			fa=sum;
		}
		printf("\n");
		sum=0,fa=0;
		for(int i=0;i<n;i++)
		{
			if(i&&a[i]!=1&&a[i-1]!=1)
			{
				for(int j=0;j<a[i]-1;j++)
				{
					sum++;
					printf("%d ",fa);
				}
				sum++;
				printf("%d ",fa-1);
				fa=sum;
			}
			else
			{
				for(int j=0;j<a[i];j++)
				{
					sum++;
					printf("%d ",fa);
				}
				fa=sum;
			}
		}
	}
	return 0;
}
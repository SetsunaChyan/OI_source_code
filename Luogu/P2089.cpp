#include <stdio.h>

int i,n,a[10],ans=0;

int sum()
{
	int i=0,s=0;
	for(i=0;i<10;i++)
	{
		s+=a[i];
	}
	return s;
}

int dfs(int l,int fl)
{
	int i;
	for(i=1;i<=3;i++)
	{
		a[l]=i;
		if(l==9&&sum()==n) 
		{
			ans++;
			if(fl)
			{
				int j;
				for(j=0;j<10;j++)
					printf("%d ",a[j]);
				printf("\n");
			}
		}
		else
			if(l<9) dfs(l+1,fl);
		a[l]=1;
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	if(n>30||n<10) 
	{
		printf("0");
		return 0; 
	}
	for(i=0;i<10;i++) a[i]=1;
	dfs(0,0);
	printf("%d\n",ans);
	dfs(0,1);
	return 0;
}

#include <stdio.h>

int i,n,a[100000];

void quick_sort(int l,int r)
{
	int temp,i=l,j=r,x=a[(l+r)/2];
	
	do
	{
		while(a[i]<x) i++;
		while(a[j]>x) j--;
		if(i<=j)
		{
			temp=a[i];a[i]=a[j];a[j]=temp;
			i++;j--;
		}
	}while(i<=j);
	
	if(i<r) quick_sort(i,r);
	if(j>l) quick_sort(l,j);	
}

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

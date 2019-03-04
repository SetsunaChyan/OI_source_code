#include <stdio.h>

int n,a[10000],ans=0;

int quick_sort(int l,int r)
{
	int i=l,j=r,x=a[(i+j)/2],t;
	while(i<=j)
	{
		while(a[i]<x) i++;
		while(a[j]>x) j--;
		if(i<=j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t; 
			i++;j--; 
		}
	}
	if(i<r) quick_sort(i,r);
	if(j>l) quick_sort(l,j); 
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(0,n-1);
	ans+=a[0]*(n-1);
	for(int i=1;i<n;i++)
		ans+=a[i]*(n-i);
	printf("%d\n",ans);
	return 0;
}

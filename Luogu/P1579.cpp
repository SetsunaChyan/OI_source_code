#include <stdio.h>
#include <math.h>

int size=0,zs[20000];

int binary_find(int x)
{
	int l=0,r=size-1;
	while(r>=l)
	{
		int i=(l+r)/2;
		if(zs[i]==x) return 1;
		if(zs[i]<x) l=i+1; else r=i-1;
	}
	return 0;
}

int is_prime(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
} 

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		if(is_prime(i))
			zs[size++]=i;
	}
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(binary_find(n-zs[i]-zs[j])) 
			{
				printf("%d %d %d",zs[i],zs[j],n-zs[i]-zs[j]);
				return 0;
			}
	return 0;
}

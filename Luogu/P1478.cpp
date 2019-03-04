#include <stdio.h>

int n,s,yz,b,h[5000],a[5000]; 

void quick_sort(int l,int r)
{
	int i=l,j=r,m=a[(i+j)/2],t;
	do
	{
		while(a[i]<m)i++;
		while(a[j]>m)j--;
		if(i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			t=h[i];h[i]=h[j];h[j]=t;
			i++;j--;
		}
	}while(i<=j);
	if(i<r) quick_sort(i,r);
	if(j>l) quick_sort(l,j);
}

int main()
{
	int i,ans=0;
	scanf("%d%d%d%d",&n,&s,&yz,&b);
	for(i=0;i<n;i++) scanf("%d%d",&h[i],&a[i]);
	quick_sort(0,n-1);
	for(i=0;i<n;i++)
	{
		if(h[i]<=yz+b&&a[i]<=s)
		{
			s-=a[i];
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

#include <stdio.h>

int a[10000],n,m;

int next()
{
	int i,k,m,t;
	for(i=0;i<n-1;i++)
		if(a[i]<a[i+1]) k=i;
	m=k+1;
	for(i=k+1;i<n;i++)
		if(a[i]>a[k]&&a[i]<a[m]) m=i;
	t=a[m];a[m]=a[k];a[k]=t;
	for(i=k+1;i<=(n+k)/2;i++)
	{
		t=a[i];a[i]=a[n-(i-k)];a[n-(i-k)]=t;
	}
}

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<m;i++) next();
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}

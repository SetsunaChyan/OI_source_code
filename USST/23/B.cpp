#include <cstdio>

int a[100005],n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int i,flag=1;
	for(i=0;i<n;i++)
		if(a[i]>=a[i+1]) break;
	for(;i<n;i++)
		if(a[i]<=a[i+1]) flag=0;
	flag=flag&&a[0]<a[1]&&a[n-2]>a[n-1];
	if(flag)
		printf("Yes");
	else
		printf("No");
	
	return 0;
}

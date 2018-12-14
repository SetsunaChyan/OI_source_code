#include <cstdio>

int n;
long long a[1001],b[1001];

int check()
{
	int ret=0;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]) ret++;
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		long long d=a[i]-a[i-1];
		b[i]=a[i];
		for(int j=i-1;j>=0;j--) b[j]=b[j+1]-d;
		for(int j=i+1;j<n;j++) b[j]=b[j-1]+d;
		if(check()<=3)
		{
			for(int k=0;k<n-1;k++)
				printf("%d ",b[k]);
			printf("%d",b[n-1]);
			return 0;
		}	
	}
	return 0;
}
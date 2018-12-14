#include <cstdio>
#include <algorithm>

const int N=2e6+40;
int a[N],n,k;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	std::sort(a,a+n);
	if(k==0)
	{
		if(a[0]!=1)
			printf("1");
		else
			printf("-1");
		return 0;
	}
	int temp=a[k-1];
	for(int i=k;i<n;i++)
		if(a[i]==temp)
		{
			printf("-1");
			return 0;
		}
	printf("%d",temp);
	return 0;
}
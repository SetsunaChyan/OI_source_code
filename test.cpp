#include <cstdio>
#include <algorithm>

int a[1000];

int main()
{
	freopen("input.txt","r",stdin);
	int _;
	scanf("%d",&_);
	while(_--)
	{
		int ta,n;
		scanf("%d%d",&ta,&n);
		for(int i=0;i<n;i++)
		 	scanf("%d",&a[i]);
		for(int i=0;i<n;i+=2)
		{
			std::sort(a,a+i+1);
			printf("%d ",a[i/2]);
		}
		printf("\n");
	}
	return 0;
}
#include <cstdio>

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	int n,p=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		p=max(p,x);
	}
	printf("%d",p);
	return 0;
}
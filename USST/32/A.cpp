#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x+=y+z;
		printf("%lld\n",1ll<<x);
	}
	return 0;
}
#include <stdio.h>

int main()
{
	int ans=0,n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		ans+=n/i;
	printf("%d",ans);
	return 0;
}

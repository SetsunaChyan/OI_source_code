#include <cstdio>

int n,l,a,x,y,lx=0,ly=0,ans=0;

int main()
{
	scanf("%d%d%d",&n,&l,&a);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		ans+=(x-(lx+ly))/a;
		lx=x,ly=y;
	}
	ans+=(l-(lx+ly))/a;
	printf("%d",ans);
	return 0;
}
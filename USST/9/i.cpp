#include <cstdio>

int a,b,c,d;

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==b&&b==c&&c==d)
		printf("Fish At Constant Depth");
	else if(a<b&&b<c&&c<d)
		printf("Fish Rising");
	else if(a>b&&b>c&&c>d)
		printf("Fish Diving");
	else
		printf("No Fish");
	return 0;
}
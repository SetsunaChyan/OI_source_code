#include <cstdio>
#include <memory.h>

int an=0,bn=0;
struct node
{
	int q,w;
}a[6000],b[6000];

inline int abs(int x){return x<0?-x:x;}

int main()
{
	char c;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(~scanf("%c",&c))
	{
		if(c=='E') break;
		if(c!='W'&&c!='L') continue;
		if(c=='W')
		{
			a[an].q++;
			b[bn].q++;
		}
		else
		{
			a[an].w++;
			b[bn].w++;
		}
		if(a[an].q>=11||a[an].w>=11)
			if(abs(a[an].q-a[an].w)>=2)
				an++;
		if(b[bn].q>=21||b[bn].w>=21)
			if(abs(b[bn].q-b[bn].w)>=2)
				bn++;
	}
	for(int i=0;i<=an;i++)
		printf("%d:%d\n",a[i].q,a[i].w);
	printf("\n");
	for(int i=0;i<=bn;i++)
		printf("%d:%d\n",b[i].q,b[i].w);
	return 0;
}
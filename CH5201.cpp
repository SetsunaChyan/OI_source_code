#include <cstdio>
#include <memory.h>

int n,m,f[10001],a[101];

void zopack(int w)
{
	for(int i=m;i>=w;i--)
		f[i]+=f[i-w];
}

int main()
{
	memset(f,0,sizeof(f));
	f[0]=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		zopack(x);
	}
	printf("%d",f[m]);
	return 0;
}
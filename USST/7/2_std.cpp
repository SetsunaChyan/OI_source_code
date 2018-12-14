#include <cstdio>
#include <memory.h>

long long a[1001];

long long f(int x)
{
	if(a[x]) return a[x];
	for(int i=0;i<=x/2;i++)
		a[x]+=f(i);
	return a[x];
}

int main()
{	
	freopen("data.in","r",stdin);
    freopen("data1.out","w",stdout);
	int x;
	memset(a,0,sizeof(a));
	a[0]=1;
	while(~scanf("%d",&x))
		printf("%lld\n",f(x));
	return 0;
}
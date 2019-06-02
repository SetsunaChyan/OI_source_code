#include <cstdio>
#include <memory.h>

typedef long long ll;
ll f[60];

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		memset(f,0,sizeof(f));
    	int a,b;
    	scanf("%d%d",&a,&b);
    	f[a]=1;
    	for(int i=a;i<=b;i++)
    	{
    	    f[i+2]+=f[i];
    	    f[i+1]+=f[i];
    	}
    	printf("%lld\n",f[b]);	
	}
    return 0;
}

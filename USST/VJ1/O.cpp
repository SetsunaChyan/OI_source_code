#include <cstdio>
typedef long long ll;
ll f[44];

int main()
{
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=40;i++)
		f[i]=f[i-1]+f[i-2];	
	int _,n;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);
		printf("%lld\n",f[n]);
	}
	return 0;
}

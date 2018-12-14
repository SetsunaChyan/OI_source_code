#include <cstdio>

int main()
{
	int n,ans=0;;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k=i,f=0,g=0;
		while(k)
		{
			f+=k%10;
			k/=10;
		}
		k=i;
		while(k)
		{
			g+=(k&1);
			k>>=1;
		}
		if(f==g) ans++;
	}
	printf("%d",ans);
	return 0;
}
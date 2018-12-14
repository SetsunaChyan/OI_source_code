#include <cstdio>

int main()
{
	int n,k,m,ans;
	scanf("%d%d%d",&n,&k,&m);
	if(n<m) 
		printf("%d",k); 
	else 
	{
		ans=n*k/m;
		if(n*k%m) ans++;
		printf("%d",ans);
	}
	return 0;
}
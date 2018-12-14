#include <cstdio>
#include <memory.h>
#include <cmath>

int n,vis[18],a[18];

inline bool is_prime(int x)
{
	int t=sqrt(x);
	for(int i=2;i<=t;i++)
		if(x%i==0) return false;
	return true;
}

void dfs(int dep)
{
	if(dep==n)
	{
		if(is_prime(a[dep-1]+1))
		{
			printf("1");
			for(int i=1;i<n;i++)
				printf(" %d",a[i]);
			printf("\n");
		}
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]&&is_prime(a[dep-1]+i))
		{
			vis[i]=1;
			a[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}

int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	vis[1]=1;
	a[0]=1;
	dfs(1);
	return 0;
}
#include <cstdio>
#include <memory.h>

int flag=0,n,m,c[13][13],a[13],used[13];

void dfs(int now,int sum)
{
	if(now==n&&sum==m)
	{
		flag=1;
		for(int i=0;i<n;i++) printf("%d ",a[i]);
	}
	if(now==n) return;
	for(int i=1;i<=n;i++)
	{
		if(used[i]) continue;
		used[i]=1;
		a[now]=i;
		if(sum+c[n-1][now]*i>m) {used[i]=0;break;}
		dfs(now+1,sum+c[n-1][now]*i);
		if(flag) return;
		used[i]=0;
	}
}

int main()
{
	memset(used,0,sizeof(used));
	memset(c,0,sizeof(c));
	c[0][0]=1;
	for(int i=1;i<13;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	scanf("%d%d",&n,&m);
	dfs(0,0);
	return 0;
}
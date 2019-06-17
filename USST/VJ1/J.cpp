#include <cstdio>
#include <memory.h>
#include <algorithm>

const int mv[4][2]={1,0,0,1,-1,0,0,-1};
int n,m,k,a[55][55],f[2505],flag;

void dfs(int x,int y,int last)
{
	if(flag) return;
	if(last==0)
	{
		flag=1;
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
				printf("%d ",a[i][j]);
			printf("%d\n",a[i][m]);
		}	
		return;
	}
	for(int i=1;i<=k;i++)
		if(f[i]>(last+1)/2) return;
	int flg,dx,dy;
	if(y==m) dy=1,dx=x+1; else dy=y+1,dx=x;
	for(int i=1;i<=k;i++)
	{
		if(!f[i]) continue;
		flg=0;
		for(int j=0;j<4;j++)
			if(a[x+mv[j][0]][y+mv[j][1]]==i) flg=1;
		if(flg) continue;
		a[x][y]=i;
		f[i]--;
		dfs(dx,dy,last-1);
		a[x][y]=0;
		f[i]++;
	}
}

void solve(int cs)
{
	flag=0;
	memset(a,0,sizeof(a));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++) scanf("%d",&f[i]);
	printf("Case #%d:\n",cs);
	dfs(1,1,n*m);
	if(!flag) printf("NO\n");	
}

int main()
{
	int _;
	scanf("%d",&_);
	for(int i=1;i<=_;i++) solve(i);	
	return 0;
} 

#include <cstdio>
#include <memory.h>

int n,m,c[205][205],p[1001],f[1001][205][205];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	memset(f,0x3f,sizeof(f));
	f[0][1][2]=0;
	f[0][2][1]=0;
	p[0]=3;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&c[i][j]);
	for(int i=1;i<=m;i++) scanf("%d",&p[i]);
	for(int i=0;i<m;i++)
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
			{
				if(x!=p[i]&&y!=p[i]&&x!=y) 
				{
					if(x!=p[i+1]&&y!=p[i+1]) f[i+1][x][y]=min(f[i+1][x][y],f[i][x][y]+c[p[i]][p[i+1]]);
					if(p[i]!=p[i+1]&&y!=p[i+1]) f[i+1][p[i]][y]=min(f[i+1][p[i]][y],f[i][x][y]+c[x][p[i+1]]);
					if(p[i]!=p[i+1]&&x!=p[i+1]) f[i+1][x][p[i]]=min(f[i+1][x][p[i]],f[i][x][y]+c[y][p[i+1]]);
				}
			}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=min(f[m][i][j],ans);
	printf("%d",ans);
	return 0;
}
#include <cstdio>
#include <memory.h>

int n,m,k,f[16][226][16][16][2][2],mp[16][16],pre[16][16];
struct node
{
	int lay,j,l,r,t1,t2;
}path[16][226][16][16][2][2],dest;

inline void savepath(node &p,int lay,int j,int l,int r,int t1,int t2)
{
	p.lay=lay;p.j=j;p.l=l;p.r=r;p.t1=t1;p.t2=t2;
}

int main()
{
	memset(f,0,sizeof(f));
	memset(pre,0,sizeof(pre));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
			pre[i][j]=pre[i][j-1]+mp[i][j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			for(int l=1;l<=m;l++)
				for(int r=l;r<=m;r++)
				{
					if(j==r-l+1&&f[i][j][l][r][0][1]<f[i-1][0][0][0][0][1]+pre[i][r]-pre[i][l-1])
					{
						f[i][j][l][r][0][1]=f[i-1][0][0][0][0][1]+pre[i][r]-pre[i][l-1];
						savepath(path[i][j][l][r][0][1],i-1,0,0,0,0,1);
						break;
					}
					if(j<=r-l+1) break;
					for(int p=1;p<=m;p++)
						for(int q=p;q<=m;q++)
						{
							if(l<=p&&q<=r&&f[i][j][l][r][0][1]<f[i-1][j-r+l-1][p][q][0][1]+pre[i][r]-pre[i][l-1])
							{
								f[i][j][l][r][0][1]=f[i-1][j-r+l-1][p][q][0][1]+pre[i][r]-pre[i][l-1];
								savepath(path[i][j][l][r][0][1],i-1,j-r+l-1,p,q,0,1);
							}
							for(int y=0;y<=1;y++)
							{
								if(l<=p&&r<=q&&r>=p&&f[i][j][l][r][0][0]<f[i-1][j-r+l-1][p][q][0][y]+pre[i][r]-pre[i][l-1])
								{
									f[i][j][l][r][0][0]=f[i-1][j-r+l-1][p][q][0][y]+pre[i][r]-pre[i][l-1];
									savepath(path[i][j][l][r][0][0],i-1,j-r+l-1,p,q,0,y);
								}
								if(p<=l&&q<=r&&l<=q&&f[i][j][l][r][1][1]<f[i-1][j-r+l-1][p][q][y][1]+pre[i][r]-pre[i][l-1])
								{
									f[i][j][l][r][1][1]=f[i-1][j-r+l-1][p][q][y][1]+pre[i][r]-pre[i][l-1];
									savepath(path[i][j][l][r][1][1],i-1,j-r+l-1,p,q,y,1);
								}
							}
							for(int x=0;x<=1;x++)
								for(int y=0;y<=1;y++)
								{
									if(p<=l&&r<=q&&f[i][j][l][r][1][0]<f[i-1][j-r+l-1][p][q][x][y]+pre[i][r]-pre[i][l-1])
									{
										f[i][j][l][r][1][0]=f[i-1][j-r+l-1][p][q][x][y]+pre[i][r]-pre[i][l-1];
										savepath(path[i][j][l][r][1][0],i-1,j-r+l-1,p,q,x,y);
									}
								}
						}
				}
	int maxn=0;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			for(int r=l;r<=m;r++)
				for(int x=0;x<=1;x++)
					for(int y=0;y<=1;y++)
						if(maxn<f[i][k][l][r][x][y])
						{
							maxn=f[i][k][l][r][x][y];
							dest.lay=i;dest.j=k;dest.l=l;dest.r=r;dest.t1=x;dest.t2=y;
						}
	printf("Oil : %d\n",maxn);
	while(dest.j!=0&&dest.lay!=0)
	{

		for(int i=dest.l;i<=dest.r;i++)
			printf("%d %d\n",dest.lay,i);
		dest=path[dest.lay][dest.j][dest.l][dest.r][dest.t1][dest.t2];
	}
	return 0;
}
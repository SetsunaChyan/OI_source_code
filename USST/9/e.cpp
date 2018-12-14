#include <cstdio>
#include <memory.h>

const int r[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
const int nxt[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int sum=0,n,f[101][101];

int main()
{
	scanf("%d",&n);
	int x=n/2,y=n/2,now=1,dir=3;
	while(now<=n*n)
	{
		f[x][y]=now++;
		if(f[x+r[dir][0]][y+r[dir][1]])
		{
			x+=nxt[dir][0];y+=nxt[dir][1];
		}
		else
		{
			x+=r[dir][0];y+=r[dir][1];
			dir=(dir+1)%4;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d",f[i][0]);
		for(int j=1;j<n;j++)
			printf(" %d",f[i][j]);
		printf("\n");
	}
	for(int i=0;i<n;i++)
		sum+=f[i][i]+f[i][n-i-1];
	printf("%d",sum-1);
	return 0;
}
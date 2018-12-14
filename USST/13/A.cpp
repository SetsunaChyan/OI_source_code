#include <cstdio>
#include <memory.h>

const int move[4][2]={1,0,0,1,-1,0,0,-1};
int hd=0,ed=0,n,m,x1,x2,y1,y2;
char s[205][205];
struct node
{
	int x,y,cost;
}e[50000];

bool rp(int x,int y)
{
	for(int i=0;i<ed;i++)
		if(x==e[i].x&&y==e[i].y) return true;
	return false;
}

int main()
{
	int flag=0;
	scanf("%d%d",&n,&m);
	memset(s,' ',sizeof(s));
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 	
		{
			scanf("%c",&s[i][j]);
			if(s[i][j]!=' '&&s[i][j]!='X')
			{
				s[i][j]=' ';
				break;
			}
		}
		if(i!=n) getchar();
	}
	/*printf("ssss\n\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d ",i);
		for(int j=1;j<=m+1;j++)
			printf("%c",s[i][j]);
		printf("\n");
	}*/
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	e[0].x=x1;
	e[0].y=y1;
	e[0].cost=0;
	do
	{
		for(int i=0;i<4;i++)
		{
			int dx=e[hd].x+move[i][0],dy=e[hd].y+move[i][1];
			if(dx>=0&&dx<=n+1&&dy>=0&&dy<=m+1&&s[dx][dy]!='X')
			{
				if(rp(dx,dy)) continue;
				ed++;
				e[ed].x=dx;
				e[ed].y=dy;
				//if(dx==0||dx>n||dy==0||dy>m) 
					e[ed].cost=e[hd].cost+1; 
				//else
				//	e[ed].cost=e[hd].cost; 
				if(dx==x2&&dy==y2)
				{
					flag=1;
					printf("%d",e[hd].cost);
					break;
				}
			}
		}
		//printf("dd %d %d %d\n",e[hd].x,e[hd].y,e[hd].cost);
		if(flag) break;
		hd++;
	}while(hd<=ed);
	if(!flag) printf("NO");
	return 0;
}
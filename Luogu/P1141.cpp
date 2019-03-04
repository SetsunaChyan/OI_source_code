#include <cstdio>

struct node
{
	int x,y;
}q[1000000];

const int move[4][2]={1,0,0,1,-1,0,0,-1};
int n,qe,a[1000][1000],ans[1000][1000],e,h;

void bfs(int k,int x,int y)
{
	h=0;e=0;
	ans[x][y]=k;
	q[h].x=x;
	q[h].y=y;
	do
	{
		for(int i=0;i<4;i++)
		{
			int tx=q[h].x+move[i][0],ty=q[h].y+move[i][1];
			if(tx>=0&&tx<n&&ty>=0&&ty<n&&(!ans[tx][ty]||ans[tx][ty]!=k&&k)&&(a[tx][ty]==1-a[q[h].x][q[h].y]))
			{
				e++;
				if(!k) 
					ans[tx][ty]++;
				else
					ans[tx][ty]=k;
				q[e].x=tx;
				q[e].y=ty;
			}
		}
		h++;
	}while(h<=e);
}

int main()
{
	scanf("%d%d",&n,&qe);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			char c;
			do{scanf("%c",&c);}while(c-'0'!=0&&c-'0'!=1);
			a[i][j]=c-'0';
			ans[i][j]=0;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(ans[i][j]) continue;
			bfs(0,i,j);
			if(e==0) e=1;
			bfs(e,i,j);
		}

	while(qe--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",ans[x-1][y-1]);
	}

	return 0;
}
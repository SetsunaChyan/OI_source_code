#include <cstdio>
#include <memory.h>

const int move[4][2]={1,0,0,-1,-1,0,0,1};
int n,m,flag=0,vis[100][100];
char s[100][100];

void dfs(int x,int y,int nowdir,int cg)
{
	vis[x][y]=1;
	if(s[x][y]=='T')
	{
		flag=1;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int tmp=cg;
		if((i-nowdir+4)%2==1) tmp+=1; 
		else if(i!=nowdir) tmp+=2;
		if(tmp>2) continue;
		int dx=x+move[i][0],dy=y+move[i][1];
		if(dx>=0&&dx<n&&dy>=0&&dy<m&&(s[dx][dy]=='.'||s[dx][dy]=='T')&&!vis[dx][dy])
			dfs(dx,dy,i,tmp);
	}
	vis[x][y]=0;
}


int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int x=0;x<n;x++)
		for(int y=0;y<m;y++)
			if(s[x][y]=='S')	
				for(int i=0;i<4;i++)
					dfs(x,y,i,0);
	if(flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}

/*
4 5
S***T
.....
.....
.....
*/


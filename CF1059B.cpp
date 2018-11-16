#include <cstdio>
#include <memory.h>

char p[1050][1050];
int n,m,vis[1050][1050];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

bool check(int x,int y)
{
	int flag=0;
	for(int i=max(x-1,0);i<=min(x+1,n);i++)
		for(int j=max(y-1,0);j<=min(y+1,m);j++)
		{
			if(i==x&&y==j) continue;
			if(p[i][j]!='#') return false;
		}
	return true;
}

void f(int x,int y)
{
	for(int i=max(x-1,0);i<=min(x+1,n);i++)
		for(int j=max(y-1,0);j<=min(y+1,m);j++)
		{
			if(i==x&&y==j) continue;
			vis[i][j]=1;
		}	
}

bool fill(int x,int y)
{
	for(int i=max(x-1,1);i<=min(x+1,n-1);i++)
		for(int j=max(y-1,1);j<=min(y+1,m-1);j++)
		{
			if(i==x&&y==j) continue;
			if(check(i,j))
			{
				f(i,j);
				return true;
			}
		}
	return false;
}

int main()
{
	memset(vis,0,sizeof(vis));
	int flag=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",p[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j]&&p[i][j]=='#')
				if(!fill(i,j)) flag=1;
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
#include <cstdio>
#include <memory.h>

const int pp[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int x,y,n,m;
long long f[21][21];

inline bool g(int a,int b)
{
	if(a==x&&b==y) return false;
	for(int i=0;i<8;i++)
		if(a==x+pp[i][0]&&b==y+pp[i][1]) return false;
	return true;
}

int main()
{	
	memset(f,0,sizeof(f));
	scanf("%d%d%d%d",&n,&m,&x,&y);
	f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(!g(i,j)) continue;
			if(i) f[i][j]+=f[i-1][j];
			if(j) f[i][j]+=f[i][j-1];
		}
	printf("%lld",f[n][m]);
	return 0;
}
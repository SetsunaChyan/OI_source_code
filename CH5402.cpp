#include <cstdio>
#include <memory.h>

int n,m,cnt=0,f[301][301],val[301],e[301],head[301],nxt[301];

inline void addedge(int x,int y)
{
	nxt[cnt]=head[x];
	head[x]=cnt;
	e[cnt]=y;
	cnt++;
}

inline int max(int a,int b){return a>b?a:b;}

void dp(int now)
{
	for(int i=head[now];~i;i=nxt[i])
	{
		dp(e[i]);
		for(int j=m;j>=0;j--)
			for(int k=0;k<=j;k++)
				f[now][j]=max(f[now][j],f[now][j-k]+f[e[i]][k]);
	}
	if(now!=0)
		for(int i=m;i>=1;i--)
			f[now][i]=f[now][i-1]+val[now];
}

int main()
{
	memset(f,0,sizeof(f));
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d%d",&x,&val[i]);
		addedge(x,i);
	}
	dp(0);
	printf("%d",f[0][m]);
	return 0;
}
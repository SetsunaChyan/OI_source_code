#include <cstdio>
#include <memory.h>

int val[6000],cnt=0,e[6000],head[6000],nxt[6000],n,f[6000][2],vis[6000];

inline void addedge(int x,int y)
{
	e[cnt]=y;nxt[cnt]=head[x];head[x]=cnt;cnt++;
}

inline int max(int a,int b){return a>b?a:b;}

void dp(int now)
{
	f[now][0]=0;f[now][1]=val[now];
	for(int i=head[now];~i;i=nxt[i])
	{
		dp(e[i]);
		f[now][0]+=max(f[e[i]][0],f[e[i]][1]);
		f[now][1]+=f[e[i]][0];
	}
}

int main()
{
	int st;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&val[i]);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		addedge(y,x);
		vis[x]++;
	}
	scanf("%*d%*d");
	for(int i=0;i<n;i++)
		if(!vis[i]) {st=i;break;}
	dp(st);
	printf("%d",max(f[st][0],f[st][1]));
	return 0;
}
#include <cstdio>
#include <memory.h>

const int MAXN=500005;
struct edge
{
	int v,next;  
}e[2*MAXN];
int en=0,front[MAXN],n,m,root,lg[MAXN],depth[MAXN],f[MAXN][21];

inline void add_edge(int u,int v)
{
	en++;
	e[en].v=v;
	e[en].next=front[u];
	front[u]=en;
}

void dfs(int now,int father)
{
	depth[now]=depth[father]+1;
	f[now][0]=father;
	for(int i=1;(1<<i)<=depth[father];i++)
		f[now][i]=f[f[now][i-1]][i-1];
	for(int i=front[now];i>0;i=e[i].next)
		if(e[i].v!=father) dfs(e[i].v,now);
}

void initialize()
{
	lg[0]=0;depth[0]=0;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
	dfs(root,0);
}

int LCA(int x,int y)
{
	if(depth[x]<depth[y])
	{
		int temp=x;
		x=y;
		y=temp;
	}
	while(depth[x]>depth[y])
		x=f[x][lg[depth[x]-depth[y]]];
	if(x==y) return x;
	for(int k=lg[depth[x]];k>=0;k--)
		if(f[x][k]!=f[y][k])
			x=f[x][k],y=f[y][k];
	return f[x][0];
}

int main()
{
	memset(front,-1,sizeof(front));
	scanf("%d%d%d",&n,&m,&root);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	initialize();
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
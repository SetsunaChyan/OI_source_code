#include <cstdio>
#include <memory.h>

const int MAXN=200050;
int cnt,n,d[MAXN],f[MAXN],head[MAXN],degree[MAXN];
struct node
{
	int nxt,to,v;
}e[MAXN<<1];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

inline void addedge(int x,int y,int v)
{
	e[cnt].nxt=head[x];
	e[cnt].v=v;
	e[cnt].to=y;
	head[x]=cnt;
	cnt++;
}

void dp1(int x,int fa)
{
	d[x]=0;
	for(int i=head[x];~i;i=e[i].nxt)
	{
		if(e[i].to!=fa) dp1(e[i].to,x); else continue;
		if(degree[e[i].to]==1) d[x]+=e[i].v;
		else d[x]+=min(e[i].v,d[e[i].to]);
	}
}

void dp2(int x,int fa)
{
	for(int i=head[x];~i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		f[e[i].to]=d[e[i].to];
		if(degree[x]==1) 
			f[e[i].to]+=e[i].v;
		else
			f[e[i].to]+=min(e[i].v,f[x]-min(e[i].v,d[e[i].to]));
		dp2(e[i].to,x);
	}
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(degree,0,sizeof(degree));
		scanf("%d",&n);
		for(int i=0;i<n-1;i++)
		{
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			addedge(x,y,v);
			addedge(y,x,v);
			degree[x]++;
			degree[y]++;
		}
		dp1(1,0);
		f[1]=d[1];
		dp2(1,0);
		int ans=-1;
		for(int i=1;i<=n;i++)
			ans=max(ans,f[i]);
		printf("%d\n",ans);
	}
	
	return 0;
}
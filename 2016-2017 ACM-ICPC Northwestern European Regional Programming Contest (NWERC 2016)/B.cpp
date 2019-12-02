#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f3f;

int n,m,x[N*10],y[N*10],tmp[N*10];
vector<int> e[N],scc[N],e2[N];
int dfn[N],low[N],timer=0,c[N],color=0;
int deg[N],dp[N];
bool vis[N];
stack<int> s;

void add(int x,int y){e[x].push_back(y);}
void add2(int x,int y){e2[x].push_back(y);}

void tarjan(int u)
{
	dfn[u]=low[u]=++timer;
	s.push(u);
	vis[u]=1;
	for(auto v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++color;
		int t;
		do
		{
			t=s.top();
			s.pop();
			c[t]=color;
			vis[t]=0;
			scc[color].push_back(t);
		}
		while(u!=t);
	}
}

void gao2(int x,int cnt)
{
	vis[x]=1;
	for(auto y:e[x])
	{
		if(vis[y]==0&&c[x]==c[y])//
			gao2(y,cnt+1),dp[y]=max(dp[y],cnt+1);
		else if(c[x]!=c[y])//
			dp[y]=max(dp[y],1+cnt);
	}
	vis[x]=0;
}

void gao()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;++i)
	{
		if(c[x[i]]!=c[y[i]])
			add2(c[x[i]],c[y[i]]),deg[c[y[i]]]++;
	}
	queue<int> q;
	for(int i=1;i<=color;++i)
		if(deg[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto i:scc[x])
			tmp[i]=dp[i];
		for(auto i:scc[x])
			gao2(i,tmp[i]);
		for(auto y:e2[x])
		{
			deg[y]--;
			if(deg[y]==0)
				q.push(y);
		}
	}
//	for(int i=1;i<=n;++i) printf("? %d ",dp[i]);
	int ans=-inf;
	for(int i=1;i<=n;++i) ans=max(ans,dp[i]);
	printf("%d",ans+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]);
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i])
			tarjan(i);
	gao();
	return 0;
}
/*
7 7
1 2
2 3
3 4
4 5
5 2
4 6
5 7

4 3
1 2
2 3
2 4
*/

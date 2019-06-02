#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <memory.h>
#include <queue>
using namespace std;

int flag,vis[1005],tot,n,m,head[1005],ans,dis[1005][1005];
struct node
{
	int to,nxt;
}e[20005];
map<string,int> id;
char s1[15],s2[15];

inline void add_edge(int x,int y)
{
	e[tot].nxt=head[x];
	e[tot].to=y;
	head[x]=tot++;
}

void bfs(int st)
{
	vis[st]=1;
	queue<pair<int,int> > q;
	q.push(make_pair(st,0));
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		dis[st][p.first]=p.second;
		for(int i=head[p.first];~i;i=e[i].nxt)
			if(!vis[e[i].to])
			{
				vis[e[i].to]=1;
				q.push(make_pair(e[i].to,p.second+1));
			}
	}
}

void solve()
{
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=0x3f3f3f3f;
	flag=0,tot=0,ans=0;
	id.clear();
	for(int i=0;i<n;i++)
	{
		scanf("%s",s1);
		id[string(s1)]=i+1;
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%s",s1,s2);
		int a=id[string(s1)],b=id[string(s2)];
		add_edge(a,b);
		add_edge(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,dis[i][j]);
	if(ans>=0x3f3f3f3f) printf("-1\n"); else printf("%d\n",ans);
} 

int main()
{
	while(~scanf("%d",&n)&&n) solve();
	return 0;
}

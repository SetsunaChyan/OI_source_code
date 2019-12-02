#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m,C,O,diso[100005],disc[100005],dis[100005],vis[100005],o[100005],c[100005];
struct edge
{
	int y,v;
	edge(int Y,int V):y(Y),v(V){}
};
vector<edge> e[100005],rev[100005];

inline void add(int x,int y,int v)
{
	e[x].emplace_back(y,v);
}

inline void revadd(int x,int y,int v)
{
	rev[x].emplace_back(y,v);
}

void dij(int dis[],vector<edge> e[],int s)
{
	//memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.emplace(0,s);
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto y:e[x])
			if(dis[x]+y.v<dis[y.y])
			{
				dis[y.y]=dis[x]+y.v;
				q.emplace(dis[y.y],y.y);
			}
	}
}

int main()
{
	scanf("%d%d%d",&n,&O,&C);
	for(int i=0,x;i<O;i++)
	{
		scanf("%d",&x);
		revadd(n+1,x,0);
	}
	for(int i=0,x;i<C;i++)
	{
		scanf("%d",&x);
		revadd(n+2,x,0);
	}
	for(int i=1,tot,x;i<=n;i++)
	{
		scanf("%d",&tot);
		for(int j=0;j<tot;j++)
			scanf("%d",&x),add(i,x,1),revadd(x,i,1);
	}
	memset(dis,0x3f,sizeof(dis));
	memset(disc,0x3f,sizeof(disc));
	memset(diso,0x3f,sizeof(diso));
	dij(diso,rev,n+1);
	dij(disc,rev,n+2);
	dij(dis,e,1);
	ll ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		ans=min(ans,(long long)diso[i]+disc[i]+dis[i]);
	if(ans>=0x3f3f3f3f) printf("impossible"); else printf("%lld",ans);
	return 0;
}

/*
3 1 1
2
3
1 2
2 3 1
1 1

3 1 1
2
3
1 2
1 1
2 1 2

7 2 1
5 7
6
1 2
1 3
1 4
2 5 6
0
1 7
0

8 2 1
7 8
3
2 2 4
2 8 3
0
2 3 6
0
1 7
0
0

6 1 1
4
5
2 2 6
1 3
2 4 5
0
0
1 5

*/

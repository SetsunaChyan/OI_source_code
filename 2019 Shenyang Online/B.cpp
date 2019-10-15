#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>g[100005];
map<int,int>mp[100005];
int n,m,k,fa[100005];
int sz[100005];
bool gg[100005];
int f(int x){return fa[x]==x?x:fa[x]=f(fa[x]);}
bool merge(int x,int y){x=f(x);y=f(y);if(x!=y)return fa[y]=x,true;return false;}
void gao(int u)
{
	queue<int>q;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();q.pop();
		for(auto v:g[u])
			if(!gg[v]&&merge(u,v))
				q.push(v);
	}
}
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)g[i].clear(),mp[i].clear(),gg[i]=0,fa[i]=i,sz[i]=0;
		for(int i=1,u,v;i<=m;i++)
			{scanf("%d%d",&u,&v);mp[u][v]++,mp[v][u]++;}
		for(int i=1,t;i<=k;i++)
			scanf("%d",&t),gg[t]=1;
		for(int i=1;i<=n;i++)
			for(auto &p:mp[i])
				g[i].push_back(p.first);
		for(int i=1;i<=n;i++)
			if(fa[i]==i&&!gg[i])
				gao(i);
		for(int i=1;i<=n;i++)
			if(!gg[i])
				sz[fa[i]]++;
		double ans=0;
		for(int i=1;i<=n;i++)
			if(gg[i])
			{
				ll cnt=0,all=0;
				for(auto p:mp[i])
				{
					cnt+=p.second;
					if(fa[p.first]!=1)
						all+=p.second*(long long)sz[fa[p.first]];
				}
				ans=max(ans,all*1.0/cnt);
			}
		printf("%.10f\n",ans+sz[1]);
	}
	return 0;
}

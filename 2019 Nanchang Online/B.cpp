#include <bits/stdc++.h>
using namespace std;
int n,m,s,k,c,p[1005];
map<pair<int,int>,int>mp;
vector<pair<int,int>>g[1005];
int d[1005];
bool h[1005],hk[1005];
int dij(int s,int fg)
{
	for(int i=1;i<=n;i++)d[i]=1e9,h[i]=0;
    d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({d[s],s});
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(h[u])continue;
        h[u]=1;
        for(auto vv:g[u])
        {
        	int v=vv.first,len=vv.second;
        	if(hk[u]&&hk[v])len=fg*len;
            if(d[v]>d[u]+len)
            {
                d[v]=d[u]+len;
                q.push({d[v],v});
            }
        }
    }
    int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,d[i]);
//	for(int i=1;i<=n;i++)
//		printf("%d:%d\n",i,d[i]);
	return ma;
}
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		memset(hk,0,sizeof(hk));
		mp.clear();
		scanf("%d%d%d%d%d",&n,&m,&s,&k,&c);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=k;i++)
			scanf("%d",p+i),hk[p[i]]=1;
		for(int i=1,u,v,l;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&l);
			if(u==v)continue;
			if(u>v)swap(u,v);
			if(mp.find({u,v})==mp.end()||mp[{u,v}]>l)
				mp[{u,v}]=l;
		}
		for(auto p:mp)
			g[p.first.first].emplace_back(p.first.second,p.second),
			g[p.first.second].emplace_back(p.first.first,p.second);
		int a=dij(s,1);
		int b=dij(p[1],0);
		//printf("%d %d\n",a,b);
		printf("%d\n",a<=b*c?a:b);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=2005;
typedef long long ll;

int _,n,m,cnt[N];
ll dis[N],ans=1e18;
bool vis[N];
vector<int> e[N];
vector<ll> v[N];

inline void add(int x,int y,ll z)
{
	e[x].push_back(y);
	v[x].push_back(z);
}

bool spfa(int s)
{
	queue<int> q;
	for(int i=0;i<=n;++i) dis[i]=1e18,vis[i]=0,cnt[i]=0;
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int f=q.front();q.pop();
		vis[f]=0;
		for(int i=0;i<e[f].size();++i)
		{
			int y=e[f][i];
			if(dis[y]>dis[f]+v[f][i])
			{
				dis[y]=dis[f]+v[f][i];
				cnt[y]=cnt[f]+1;
                if(cnt[y]>n) return 1;
				if(!vis[y])
				{
					vis[y]=1;
					q.push(y);
				}
			}
		}
	}
	for(int i=1;i<=n;++i) if(i!=s) ans=min(ans,dis[i]);
	return 0;
}

int main()
{
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;++i)
			e[i].clear(),v[i].clear();
        ll mn=1e18,z;
		for(int i=1,x,y;i<=m;++i)
		{
		    scanf("%d%d%lld",&x,&y,&z);
			add(x,y,z);
			mn=min(mn,z);
		}
        if(mn>=0)
        {
            printf("%lld\n",mn);
            continue;
        }
		ans=1e18;
		for(int i=1;i<=n;++i) add(0,i,0);
		if(spfa(0)) puts("-inf");
		else printf("%lld\n",ans);
	}
	return 0;
}

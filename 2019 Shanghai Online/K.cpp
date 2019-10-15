#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a,b,c,p[31666],up=31622;
map<ll,ll>mp;
vector<pair<ll,ll>>as,bs;
set<pair<pair<ll,ll>,pair<ll,ll>>>ans;
void init()
{
	for(int i=1;i*i<=1e9;i++)
		p[i]=i*i,mp[i*i]=i;
}
void gao(ll a,vector<pair<ll,ll>>& as)
{
	as.emplace_back(0,a);
	as.emplace_back(0,-a);
	as.emplace_back(a,0);
	as.emplace_back(-a,0);
	for(int i=1;i<=31622&&p[i]<a;i++)
		if(mp.find(a-p[i])!=mp.end())
		{
			ll t=mp[a-p[i]];
			as.emplace_back(i,t);
			as.emplace_back(-i,t);
			as.emplace_back(i,-t);
			as.emplace_back(-i,-t);
			if(t!=i)
			{
				as.emplace_back(t,i);
				as.emplace_back(-t,i);
				as.emplace_back(t,-i);
				as.emplace_back(-t,-i);
			}
		}
}
int main()
{
	init();
	int _;scanf("%d",&_);
	while(_--)
	{
		as.clear();bs.clear();
		ans.clear();
		scanf("%lld%lld%lld",&a,&b,&c);
		gao(a,as);
		gao(b,bs);
		for(auto pa:as)
			for(auto pb:bs)
			{
				ll dis=(pa.first-pb.first)*(pa.first-pb.first)+(pa.second-pb.second)*(pa.second-pb.second);
				if(dis==c*c)
					ans.insert({pa,pb});
			}
		printf("%u\n",ans.size());
		for(auto as:ans)
			printf("%lld %lld %lld %lld\n",as.first.first,as.first.second,as.second.first,as.second.second);
	}
	return 0;
}

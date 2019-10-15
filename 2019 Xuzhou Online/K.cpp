#include <bits/stdc++.h>
using namespace std;
int x[1005],y[1005],n;
vector<pair<int,int>>v;
map<pair<int,int>,int>h,vs;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i),x[i]*=2,y[i]*=2,v.emplace_back(x[i],y[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	n=v.size();
	if(n==1)return printf("0\n"),0;
	for(auto vv:v)
		vs[vv]++;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			h[{v[i].first+v[j].first,v[i].second+v[j].second}]++;
	int ma=0,ans=n;
	for(auto p:h)
		ma=max(ma,p.second);//,printf("%d %d %d\n",p.first.first,p.first.second,p.second);
	for(auto p:h)
		if(p.second==ma)
			ans=min(ans,n-2*ma-vs[p.first]);
	printf("%d\n",ans);
	return 0;
}

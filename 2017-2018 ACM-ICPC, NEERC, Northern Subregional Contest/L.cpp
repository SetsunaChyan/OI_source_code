#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

ll n;
vector<vector<ll>> ans;
vector<ll> sq;

signed main()
{
	freopen("little.in","r",stdin);
	freopen("little.out","w",stdout);
	scanf("%lld",&n);
	ll t=n;
	while(t%2==0) t/=2;
	if(t==1)
	{
		printf("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	t=sqrt(n);
	if(t>1e5)
	{
		for(int i=-10;i<=10;i++)
			if((t-i)*(t-i)==n&&t-i>1000000) sq.push_back(t-i),sq.push_back(t-i),ans.push_back(sq);
	}
	if(n>1000000)
	{
		sq.clear();
		sq.push_back(n);
		ans.push_back(sq);
	}
	t=(-1.0+sqrt(1+4*n))/2.0;
	if(t>1e5)
	{
		sq.clear();
		for(int i=-10;i<=10;i++)
			if((t-i)*(t-i+1)==n&&t-i>1000000) sq.push_back(t-i),sq.push_back(t-i+1),ans.push_back(sq);
	}
	for(ll i=2;i<=1000000;i++)
	{
		if(n%i) continue;
		vector<ll> tmp;
		t=n;
		while(t%i==0) tmp.push_back(i),t/=i;
		while(t%(i+1)==0) tmp.push_back(i+1),t/=i+1;
		if(t!=1) continue;
		ans.push_back(tmp);
	}
	ll tot=0;
	for(auto &v:ans)
		if(v.size()) tot++;
	printf("%lld\n",tot);
	for(auto &v:ans)
		if(v.size())
		{
			printf("%lld ",(int)v.size());
			for(auto p:v) printf("%lld ",p);
			printf("\n");
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

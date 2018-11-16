#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
priority_queue<ll> q1;
priority_queue<ll,vector<ll>,greater<ll> > q2;
map<ll,ll> m;

int main()
{
	ll n;
	while(scanf("%lld",&n),n)
	{
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		m.clear();
		ll sum=0;
		for(ll i=0;i<n;i++)
		{
			ll t;
			scanf("%lld",&t);
			for(ll j=0;j<t;j++)
			{
				ll x;
				scanf("%lld",&x);
				q1.push(x);
				q2.push(x);
				if(m.find(x)==m.end())
					m[x]=1;
				else
					m[x]++;
			}
			while(m[q1.top()]==0) q1.pop();
			while(m[q2.top()]==0) q2.pop();
			sum+=q1.top()-q2.top();
			m[q1.top()]--;
			m[q2.top()]--;
			q1.pop();q2.pop();
		}
		printf("%lld\n",sum);
	}	
	return 0;
}
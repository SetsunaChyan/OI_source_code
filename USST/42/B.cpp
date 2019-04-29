#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
priority_queue<ll> q1;
priority_queue<ll,vector<ll>,greater<ll> > q2;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll x;
		scanf("%lld",&x);
		q1.push(x);
		q2.push(x);
	}	
	while(q1.size()>1)
	{
		ll x,y;
		x=q1.top();
		q1.pop();
		y=q1.top();
		q1.pop();
		q1.push(x*y+1);
	}
	while(q2.size()>1)
	{
		ll x,y;
		x=q2.top();
		q2.pop();
		y=q2.top();
		q2.pop();
		q2.push(x*y+1);
	}
	printf("%llu %llu",q2.top(),q1.top());
	return 0;
}
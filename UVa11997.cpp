#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll a[750][750];
struct node
{
	ll s,b;	
	node(ll s,ll b):s(s),b(b){}
	bool operator < (const node &opt) const
	{
		return s>opt.s;
	}
};

void merge(ll a[],ll b[])
{
	priority_queue<node> q;
	for(int i=0;i<n;i++)
		q.push(node(a[i]+b[0],0));
	for(int i=0;i<n;i++)
	{
		node m=q.top();q.pop();
		a[i]=m.s;
		if(m.b+1<n) q.push(node(m.s-b[i]+b[i+1],m.b+1));
	}
}

int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) scanf("%lld",&a[i][j]);
			sort(a[i],a[i]+n);
		}
		for(int i=1;i<n;i++)
			merge(a[0],a[i]);
		for(int i=0;i<n;i++)
			printf("%lld ",a[0][i]);
		putchar('\n');
	}
	return 0;
}
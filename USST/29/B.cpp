#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int ans=0;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		q.push(x);
	}	
	while(q.size()!=1)
	{
		int a,b;
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	printf("%d",ans);
	return 0;
}
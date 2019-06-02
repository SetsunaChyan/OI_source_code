#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int n,k,vis[400005];
queue<pair<int,int> > q;

int main()
{
	scanf("%d%d",&n,&k);
	q.push(make_pair(n,0));
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		if(p.first==k)
		{
			printf("%d",p.second);
			return 0;
		}
		if(p.first>0&&!vis[p.first-1])
		{
			vis[p.first-1]=1;
			q.push(make_pair(p.first-1,p.second+1));
		}
		if(p.first<100000&&!vis[p.first+1])
		{
			vis[p.first+1]=1;
			q.push(make_pair(p.first+1,p.second+1));
		}
		if(p.first<=100000&&!vis[p.first*2])
		{
			vis[p.first*2]=1;
			q.push(make_pair(p.first*2,p.second+1));
		}
	}
	return 0;
}

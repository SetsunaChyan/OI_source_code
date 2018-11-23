#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <set>

using namespace std;

set<pair<int,int> > s;
int n,i,h,r,pre[10001];

int main()
{
	s.clear();
	scanf("%d%d%d%d",&n,&i,&h,&r);
	memset(pre,0,sizeof(pre));
	int ans=h;
	while(r--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(s.find(make_pair(x,y))!=s.end()) continue;
		s.insert(make_pair(x,y));
		pre[x+1]--;
		pre[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=pre[i];
		printf("%d\n",ans);
	}
	return 0;
}
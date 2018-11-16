#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int,int> > s;
int n,sum=0;

int main()
{
	s.clear();
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		s.insert(pair<int,int>(x,y));
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(s.find(make_pair(x,y))==s.end()) sum++;
	}
	printf("%d",sum);
	return 0;
}
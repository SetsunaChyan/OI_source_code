#include <vector>
#include <cstdio>

using namespace std;

vector<int> v[1000001];
int n,m;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<=1000000;++i)
			v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			v[x].push_back(i);
		}
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(v[y].size()<x)
				printf("0\n");
			else
				printf("%d\n",v[y][x-1]);
		}
	}
	return 0;
}
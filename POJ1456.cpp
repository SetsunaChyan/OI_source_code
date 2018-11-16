#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=1e4+50;
int fa[MAXN],n;
struct node
{
	int pro,d;
}e[MAXN];

inline bool cmp(node a,node b){return a.pro>b.pro;}

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	while(~scanf("%d",&n))
	{
		int sum=0;
		for(int i=0;i<n;i++)
			scanf("%d%d",&e[i].pro,&e[i].d);
		sort(e,e+n,cmp);
		for(int i=0;i<MAXN;i++) fa[i]=i;
		for(int i=0;i<n;i++)
		{
			int r=find(e[i].d);
			if(r>0)
			{
				sum+=e[i].pro;
				fa[r]=find(r-1);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
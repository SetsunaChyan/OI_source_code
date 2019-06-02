#include <algorithm>
#include <cstdio>
#include <memory.h>

int vis[100005];
struct node
{
	int ddl,s;
}a[1005];

inline bool cmp(node a,node b)
{
	if(a.s!=b.s) return a.s>b.s;
	return a.ddl<b.ddl;
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		memset(vis,0,sizeof(vis));
		int n,sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i].ddl);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i].s);
		std::sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			int j=a[i].ddl-1;
			for(;j>=0;j--)
				if(!vis[j])
				{
					vis[j]=1;
					break;
				}
			if(j<0) sum+=a[i].s;
		}
		printf("%d\n",sum);
	}
	return 0;
}

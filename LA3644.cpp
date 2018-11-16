#include <cstdio>
#include <memory.h>

int par[100005],rank[100005],ans;

int find(int x)
{
	return par[x]==x?x:par[x]=find(par[x]);
}

void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if(rank[x]<rank[y])
	{
		int t=x;
		x=y;
		y=t;
	}
	if(rank[x]==rank[y]) rank[x]++;
	par[y]=x;
}

int main()
{
	int x,y;
	while(~scanf("%d",&x))
	{
		ans=0;
		memset(rank,0,sizeof(rank));
		for(int i=0;i<=100000;++i) par[i]=i;
		while(x!=-1) 
		{
			scanf("%d",&y);
			if(find(x)==find(y))
				ans++;
			else
				Union(x,y);
			scanf("%d",&x);
		}
		printf("%d\n",ans);
	}
	return 0;
}
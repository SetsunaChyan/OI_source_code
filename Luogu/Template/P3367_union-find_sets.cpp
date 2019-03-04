#include <stdio.h>
#define MAX_N 1000000

int pra[MAX_N],n,m;

int find(int x)
{
	if(pra[x]==x) return x;
	return pra[x]=find(pra[x]);
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y) pra[x]=y;
}

int same(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return 1;
	return 0;
}

int main()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) pra[i]=i;
	for(i=0;i<m;i++)
	{
		int c,x,y;
		scanf("%d %d %d",&c,&x,&y);
		if(c==1)
		{
			unite(x,y);
		}
		else
		{
			if(same(x,y)) printf("Y\n"); else printf("N\n");
		}
	}
	return 0;
}

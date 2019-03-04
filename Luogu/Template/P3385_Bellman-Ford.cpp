#include <cstdio>

int n,d[2005],k,m;
struct edge
{
	int u,v,w;
}e[6005];

void initialize()
{

}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d%d",&n,&k);
		int cnt=0;
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&e[cnt].u,&e[cnt].v,&e[cnt].w);
			cnt++;
			if(e[cnt-1].w>=0)
			{
				e[cnt].v=e[cnt-1].u;
				e[cnt].u=e[cnt-1].v;
				e[cnt].w=e[cnt-1].w;
				cnt++;
			}
		}
		initialize();
		bellman_ford();
	}
	return 0;
}
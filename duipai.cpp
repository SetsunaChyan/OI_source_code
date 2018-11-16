#include <cstdio>
#include <memory.h>

int r,c,q,a[200][200];
int main()
{
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);
	while(~scanf("%d%d%d",&r,&c,&q))
	{
		memset(a,0,sizeof(a));
		while(q--)
		{
			int opt,x1,x2,y1,y2,z;
			scanf("%d%d%d%d%d",&opt,&x1,&y1,&x2,&y2);
			if(opt==3)
			{
				int min=2147483647,max=0,sum=0;
				for(int i=x1;i<=x2;i++)
					for(int j=y1;j<=y2;j++)
					{
						min=min>a[i][j]?a[i][j]:min;
						max=max<a[i][j]?a[i][j]:max;
						sum+=a[i][j];
					}
				printf("%d %d %d\n",sum,min,max);
			}
			else
			{
				scanf("%d",&z);
				for(int i=x1;i<=x2;i++)
					for(int j=y1;j<=y2;j++)
					{
						if(opt==1) a[i][j]+=z;
						else a[i][j]=z;
					}
			}
		}
	}
	return 0;
}
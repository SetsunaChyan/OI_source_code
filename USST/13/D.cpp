#include <cstdio>

int n,I,h,r,p[10005];

int main()
{
	scanf("%d%d%d%d",&n,&I,&h,&r);
	for(int i=1;i<=n;i++)
		p[i]=h;
	for(int i=0;i<r;i++)
	{
		int x,y,t;
		scanf("%d%d",&x,&y);
		//if(p[x]>p[y]) p[x]=p[y];
		if(x>y) {t=x;x=y;y=t;}
		for(int i=x+1;i<=y-1;i++) p[i]--;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",p[i]);
	return 0;
}
#include <cstdio>
#include <memory.h>

int n,m,l,cf[200005],pre[200005];

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
	pre[0]=0;
	memset(cf,0,sizeof(cf));
	scanf("%d%d%d",&n,&m,&l);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y<=l)
		{
			cf[max(1,x-(l-y))]++;
			cf[min(x+(l-y)+1,200001)]--;
		}
	}
	for(int i=1;i<=200000;i++)
		pre[i]=pre[i-1]+cf[i];
	while(m--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",pre[x]);
	}
	return 0;
}
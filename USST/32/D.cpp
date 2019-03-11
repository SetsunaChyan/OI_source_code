#include <cstdio>
#include <memory.h>

int dif[300005],n,ans=0;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	memset(dif,0,sizeof(dif));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;	
		scanf("%d",&x);
		dif[max(0,i-x)]++;
		dif[i]--;
	}
	for(int i=1;i<n;i++)
		dif[i]+=dif[i-1];
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>=dif[i]) ans++;
	}
	printf("%d",ans);
	return 0;
}
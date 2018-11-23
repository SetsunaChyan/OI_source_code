#include <cstdio>
#include <memory.h>

int n,r,mp[5002][5002],ans=0;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	scanf("%d%d",&n,&r);
	memset(mp,0,sizeof(mp));
	for(int i=0;i<n;i++)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		mp[x+1][y+1]=v;
	}
	for(int x=1;x<5002;x++)
		for(int y=1;y<5002;y++)
			mp[x][y]+=mp[x-1][y]+mp[x][y-1]-mp[x-1][y-1];
	for(int x=r;x<5002;x++)
		for(int y=r;y<5002;y++)
			ans=max(ans,mp[x][y]-mp[x-r][y]-mp[x][y-r]+mp[x-r][y-r]);
	printf("%d",ans);
	return 0;
}
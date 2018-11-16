#include <cstdio>
#include <memory.h>

const int MAXN=2e5+50;
int n,a[MAXN],vis[MAXN],b[MAXN],pos[MAXN];

int main()
{
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		int x,ans=0;
		scanf("%d",&x);
		if(vis[x])
		{
			printf("0 ");
			continue;
		}
		else
		{
			for(int j=pos[x];j>=0&&!vis[a[j]];j--)
			{
				ans++;
				vis[a[j]]=1;
			}
			printf("%d ",ans);
		}
	}
	return 0;
}
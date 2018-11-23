#include <cstdio>

int n,pre[101][101],ans=-0x3f3f3f3f;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		pre[i][0]=0;
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			pre[i][j]=pre[i][j-1]+x;
		}
	}
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
		{
			int now=0;
			for(int i=0;i<n;i++)
			{
				now+=pre[i][r]-pre[i][l-1];
				ans=max(ans,now);
				if(now<0) now=0;
			}
		}
	printf("%d",ans);
	return 0;
}
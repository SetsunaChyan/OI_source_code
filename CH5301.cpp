#include <cstdio>
#include <memory.h>

int n,f[301][301],a[301],pre[301];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]+a[i];
		f[i][i]=0;
	}
	for(int len=2;len<=n;len++)
		for(int l=1;l<=n-len+1;l++)
			for(int k=l;k<l+len-1;k++)
			{
				int r=l+len-1;
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+pre[r]-pre[l-1]);
			}
	printf("%d",f[1][n]);
	return 0;
}
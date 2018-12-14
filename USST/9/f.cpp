#include <cstdio>
#include <memory.h>

int f[101][101],a[101],n,m,t;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	memset(f,0,sizeof(f));
	scanf("%d%d%d",&n,&t,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			for(int k=t;k>=a[i];k--)
			{
				f[j][k]=max(f[j][k],f[j][k-a[i]]+1);
				f[j][k]=max(f[j][k],f[j-1][t]+1);
			}
		
	printf("%d",f[m][t]);
	return 0;
}
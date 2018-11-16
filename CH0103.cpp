#include <cstdio>
#include <memory.h>

int f[1<<20][20],n,a[20][20];
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	f[1][0]=0;
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<n;j++) if(i>>j&1)
			for(int k=0;k<n;k++)
				if((i^(1<<j))>>k&1)
					f[i][j]=min(f[i][j],f[i^(1<<j)][k]+a[k][j]);
	printf("%d",f[(1<<n)-1][n-1]);
	return 0;
}
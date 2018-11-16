#include <cstdio>
#include <memory.h>

int f[110][110],a[1100],n,m,t;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		char c;
		memset(f,0,sizeof(f));
		scanf("%d%d%d",&n,&t,&m);
		for(int i=1;i<=n;i++) scanf("%d%*c",&a[i]);
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--)
				for(int k=t;k>=a[i];k--)
				{
					f[j][k]=max(f[j][k],f[j][k-a[i]]+1);
					f[j][k]=max(f[j][k],f[j-1][t]+1);
				}
		printf("%d\n",f[m][t]);
		if(_) printf("\n");
	}
	return 0;
}
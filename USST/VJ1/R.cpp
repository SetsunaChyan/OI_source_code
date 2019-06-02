#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

int n,a,b,k,f[200][200],z[200];

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d%d%d",&n,&a,&b,&k);	
		for(int i=0;i<n;i++)
			scanf("%d",&z[i]);
		for(int i=1;i<n;i++)
			for(int j=1;j<=k;j++)
				for(int x=a;x<=b;x++)
				{
					if(i-x<0) continue;
					f[i][j]=max(f[i][j],f[i-x][j-1]+z[i]);
				}
		int ans=0;
		for(int i=0;i<n;i++) 
			ans=max(ans,f[i][k]);
		printf("%d\n",ans+z[0]);
	}
	
	
	return 0;
}

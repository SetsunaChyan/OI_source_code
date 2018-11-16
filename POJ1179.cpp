#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF=0x3f3f3f3f;
int n,f[110][110][2],maxn=-INF;

struct node
{
	int val;
	char opt;
}e[110];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	scanf("%d",&n);
	scanf(" %c",&e[n].opt);e[2*n].opt=e[n].opt;
	for(int i=1;i<n;i++)
	{
		scanf("%d %c",&e[i].val,&e[i].opt);
		e[i+n].val=e[i].val;
		e[i+n].opt=e[i].opt;
		f[i][i][0]=f[i+n][i+n][0]=f[i][i][1]=f[i+n][i+n][1]=e[i].val;
	}
	scanf("%d",&e[n].val);e[2*n].val=e[n].val;
	f[n][n][0]=f[2*n][2*n][0]=f[n][n][1]=f[2*n][2*n][1]=e[n].val;

	for(int len=2;len<=n;len++)
		for(int l=1;l<=2*n-len+1;l++)
		{
			int r=l+len-1;
			f[l][r][0]=INF;f[l][r][1]=-INF;
			for(int k=l;k<r;k++)
				if(e[k].opt=='t')
				{
					f[l][r][0]=min(f[l][k][0]+f[k+1][r][0],f[l][r][0]);
					f[l][r][1]=max(f[l][k][1]+f[k+1][r][1],f[l][r][1]);
				}
				else
					for(int x=0;x<=1;x++)
						for(int y=0;y<=1;y++)
						{
							int z=f[l][k][x]*f[k+1][r][y];
							f[l][r][0]=min(z,f[l][r][0]);
							f[l][r][1]=max(z,f[l][r][1]);
						}
		}
	for(int i=1;i<=n;i++)
		maxn=max(maxn,f[i][i+n-1][1]);
	printf("%d\n",maxn);
	for(int i=1;i<=n;i++)
		if(f[i][i+n-1][1]==maxn)
			printf("%d ",i);
	return 0;
}
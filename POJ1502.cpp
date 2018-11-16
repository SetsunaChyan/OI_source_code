#include <cstdio>
#include <memory.h>

const int MAXN=105;
const int INF=0x3f3f3f3f;
int n,dis[MAXN][MAXN];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

inline int read()
{
	int ret=0;
	char c=0;
	while(!(c=='x'||(c>='0'&&c<='9'))) c=getchar();
	if(c=='x') return INF;
	while(c>='0'&&c<='9') {ret=10*ret+c-'0';c=getchar();}
	return ret;
}

int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
		{
			int x=read();
			dis[i][j]=dis[j][i]=x;
		}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int j=0;j<n;j++)
		ans=max(ans,dis[0][j]);
	printf("%d\n",ans);
	return 0;
}
#include <cstdio>
#include <memory.h>

typedef long long ll;
int n,m;
ll f[100][51][51],a[51][51];

inline ll max(ll a,ll b){return a>b?a:b;}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	memset(f,0x80,sizeof(f));
	f[0][1][1]=a[1][1];
	for(int i=0;i<n+m-2;i++)
		for(int x1=1;x1<=n;x1++)
			for(int x2=1;x2<=n;x2++)
			{
				if(i-x1+2<m&&i-x2+2<m)
				{
					if(x1==x2) f[i+1][x1][x2]=max(f[i+1][x1][x2],f[i][x1][x2]+a[x1][i-x1+3]);
					else f[i+1][x1][x2]=max(f[i+1][x1][x2],f[i][x1][x2]+a[x1][i-x1+3]+a[x2][i-x2+3]);
				}
				if(i-x1+2<m&&x2<n)
				{
					if(x1==x2+1) f[i+1][x1][x2+1]=max(f[i+1][x1][x2+1],f[i][x1][x2]+a[x1][i-x1+3]);
					else f[i+1][x1][x2+1]=max(f[i+1][x1][x2+1],f[i][x1][x2]+a[x1][i-x1+3]+a[x2+1][i-x2+2]);
				}
				if(x1<n&&i-x2+2<m)
				{
					if(x2==x1+1) f[i+1][x1+1][x2]=max(f[i+1][x1+1][x2],f[i][x1][x2]+a[x2][i-x2+3]);
					else f[i+1][x1+1][x2]=max(f[i+1][x1+1][x2],f[i][x1][x2]+a[x2][i-x2+3]+a[x1+1][i-x1+2]);
				}
				if(x1<n&&x2<n)
				{
					if(x1==x2) f[i+1][x1+1][x2+1]=max(f[i+1][x1+1][x2+1],f[i][x1][x2]+a[x1+1][i-x1+2]);
					else f[i+1][x1+1][x2+1]=max(f[i+1][x1+1][x2+1],f[i][x1][x2]+a[x1+1][i-x1+2]+a[x2+1][i-x2+2]);
				}
			}
	printf("%lld",f[n+m-2][n][n]);
	return 0;
}
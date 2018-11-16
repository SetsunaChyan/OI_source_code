#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=2050;
int a[MAXN],d[MAXN],f[MAXN][MAXN],n;

inline int g(int x){return x<0?-x:x;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		d[i]=a[i];
	}
	sort(d,d+n);
	for(int i=0;i<n;i++) f[0][i]=g(a[0]-d[i]);
	for(int i=1;i<n;i++)
	{
		int val=f[i-1][0];
		for(int j=0;j<n;j++)
		{
			val=min(val,f[i-1][j]);
			f[i][j]=val+g(a[i]-d[j]);
		}
	}
	int ans=f[n-1][0];
	for(int i=1;i<n;i++) ans=min(ans,f[n-1][i]);
	printf("%d",ans);
	return 0;
}
#include <cstdio>

int f[3001],ans=0,n,a[3001],b[3001];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	f[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		int val=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])
				f[j]=val+1;
			else
				if(b[j]<a[i]) val=max(val,f[j]);
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}
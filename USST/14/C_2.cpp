#include <cstdio>
#include <memory.h>

int f[10005],a[10005],n,ans=0x3f3f3f3f;
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1]=0;
	for(int i=1;i<=n;i++)
	{
		if(!a[i]) continue;
		for(int j=i+1;j<=min(i+a[i],n+1);j++)
		{
			if(j>n)
				ans=min(ans,f[i]+1);
			else
				f[j]=min(f[j],f[i]+1);
		}
	}
	if(ans==0x3f3f3f3f)
		printf("-1");
	else
		printf("%d",ans);
	return 0;
}
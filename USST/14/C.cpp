#include <cstdio>
#include <memory.h>

int f[10005],a[10005],n,ans=0x3f3f3f3f;
inline int min(int a,int b){return a<b?a:b;}

void dfs(int now)
{
	if(!a[now]) return;
	if(now+a[now]>n)
		ans=min(ans,f[now]+1);
	if(now+a[now]<=n)
	{
		if(f[now]+1<f[now+a[now]])
		{
			f[now+a[now]]=f[now]+1;
			dfs(now+a[now]);
		}
	}
	if(now-a[now]>=1)
	{
		if(f[now]+1<f[now-a[now]])
		{
			f[now-a[now]]=f[now]+1;
			dfs(now-a[now]);
		}
	}
}

int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1]=0;
	dfs(1);
	if(ans==0x3f3f3f3f)
		printf("-1");
	else
		printf("%d",ans);
	return 0;
}
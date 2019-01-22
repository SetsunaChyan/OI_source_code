#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int n,vis[10005],pos[100005];
ll ans=0,a[10005],pp[10005],mmx=0x3f3f3f3f;

inline int min(int a,int b){return a<b?a:b;}

void dfs(int now,int dep,int mx,ll sum)
{
	if(vis[now]||now==pos[a[now]])
	{
		if(now==pos[a[now]]) return;
		ll det=min(sum+mmx*(dep+1)+mx,(dep-2)*mx+sum);
		vis[now]=1;
		ans+=det;
		return;
	}
	vis[now]=1;
	mx=min(mx,a[now]);
	dfs(pos[a[now]],dep+1,mx,sum+a[now]);
}

int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		pp[i]=a[i];
		mmx=min(mmx,a[i]);
	}
	sort(pp,pp+n);
	for(int i=0;i<n;i++)
		pos[pp[i]]=i;
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i,0,0x3f3f3f3f,0);
	printf("%lld",ans);
	return 0;
}
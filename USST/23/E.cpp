#include <cstdio>
#include <memory.h>

int pre[100005],cnt[100005],n,k;
//(pre[r]-pre[l-1])%k==0
//pre[r]%k==pre[l-1]%k
//cnt[i]:cnt[i]*(cnt[i]-1)/2

int main()
{
	memset(cnt,0,sizeof(cnt));
	cnt[0]++;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
		pre[i]%=k;
		if(i) pre[i]=(pre[i]+pre[i-1])%k;
		cnt[pre[i]]++;
	}
	long long ans=0;
	for(int i=0;i<=k;i++)
		ans+=(long long)cnt[i]*(cnt[i]-1)/2;
	printf("%lld",ans);
	return 0;
}

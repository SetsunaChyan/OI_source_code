#include <cstdio>
#include <algorithm>
#include <memory.h>

typedef long long ll;
int n,tot;
ll ans,m,fac[3000],vis[3000],cnt[3000];

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int main()
{
	int _;
	scanf("%d",&_);
	for(int t=1;t<=_;t++)
	{
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		tot=0,ans=0;
		scanf("%d%lld",&n,&m);
		for(int i=2;i*i<=m;i++)
			if(m%i==0) 
			{
				fac[tot++]=i;
				if(i*i!=m) fac[tot++]=m/i;
			}
		fac[tot++]=1;
		std::sort(fac,fac+tot);
		for(int i=0;i<n;i++)
		{
			ll x;
			scanf("%lld",&x);
			x=gcd(m,x);
			for(int j=0;j<tot;j++)
				if(fac[j]%x==0) vis[j]=1;
		}
		for(int i=0;i<tot;i++)
		{
			if(vis[i]!=cnt[i])
			{
				ll mf=vis[i]-cnt[i],k=m/fac[i];
				ans+=(k-1)*k/2*fac[i]*mf;
				for(int j=i;j<tot;j++)
					if(fac[j]%fac[i]==0) cnt[j]+=mf;
			}
		}
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}
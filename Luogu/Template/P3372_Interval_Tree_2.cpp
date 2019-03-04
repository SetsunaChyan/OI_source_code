#include <cstdio>

typedef long long ll;
const int MAXN=1e5+50;
ll a[MAXN],sum[MAXN<<2],add[MAXN<<2],multi[MAXN<<2],mod;
int n,q;

inline void pushup(int rt)
{
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%mod;
}

inline void pushdown(int rt,int ln,int rn)
{
	int ls=rt<<1,rs=rt<<1|1;
	sum[ls]=(sum[ls]*multi[rt]%mod+add[rt]*ln%mod)%mod;
	sum[rs]=(sum[rs]*multi[rt]%mod+add[rt]*rn%mod)%mod;
	multi[ls]=multi[ls]*multi[rt]%mod;
	multi[rs]=multi[rs]*multi[rt]%mod;
	add[ls]=(add[rt]+add[ls]*multi[rt]%mod)%mod;
	add[rs]=(add[rt]+add[rs]*multi[rt]%mod)%mod;
	add[rt]=0;
	multi[rt]=1;
}

void build(int l,int r,int rt)
{
	add[rt]=0;
	multi[rt]=1;
	if(l==r)
	{
		sum[rt]=a[l]%mod;
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(int L,int R,int opt,ll k,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		if(opt==2) 
		{
			add[rt]=(add[rt]+k)%mod;
			sum[rt]=(sum[rt]+(r-l+1)*k%mod)%mod;
		}
		else
		{
			multi[rt]=multi[rt]*k%mod;
			add[rt]=add[rt]*k%mod;
			sum[rt]=sum[rt]*k%mod;
		}
		return;
	}
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L<=m) update(L,R,opt,k,l,m,rt<<1);
	if(R>m) update(L,R,opt,k,m+1,r,rt<<1|1);
	pushup(rt);
}

ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return sum[rt];
	ll ans=0;
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L<=m) ans=(ans+query(L,R,l,m,rt<<1))%mod;
	if(R>m) ans=(ans+query(L,R,m+1,r,rt<<1|1))%mod;
	return ans;
}

int main()
{
	scanf("%d%d%lld",&n,&q,&mod);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n,1);
	while(q--)
	{
		int opt,x,y;
		ll z;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==3)
			printf("%lld\n",query(x,y,1,n,1)%mod);
		else
		{
			scanf("%lld",&z);
			update(x,y,opt,z,1,n,1);
		}
	}

	return 0;
}

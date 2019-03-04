#include <cstdio>

typedef long long ll;

const int MAXN=100005;
ll IT[MAXN<<2],add[MAXN<<2],a[MAXN];
int n,q;

void pushup(int rt){IT[rt]=IT[rt<<1]+IT[rt<<1|1];}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		IT[rt]=a[l];
		return;
	}
	int m=(r+l)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

inline void pushdown(int rt,int ln,int rn)
{
	if(add[rt])
	{
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		IT[rt<<1]+=add[rt]*ln;
		IT[rt<<1|1]+=add[rt]*rn;
		add[rt]=0;
	}
}

void update(int L,int R,ll C,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		IT[rt]+=C*(r-l+1);
		add[rt]+=C;
		return;
	}
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L<=m) update(L,R,C,l,m,rt<<1);
	if(R>m) update(L,R,C,m+1,r,rt<<1|1);
	pushup(rt);
}

ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return IT[rt];
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	ll ANS=0;
	if(L<=m) ANS+=query(L,R,l,m,rt<<1);
	if(R>m) ANS+=query(L,R,m+1,r,rt<<1|1);
	return ANS;
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n,1);
	for(int i=0;i<q;i++)
	{	
		int opt,x,y,k;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)
		{
			scanf("%d",&k);
			update(x,y,k,1,n,1);
		}
		else
			printf("%lld\n",query(x,y,1,n,1));
	}

	return 0;
}
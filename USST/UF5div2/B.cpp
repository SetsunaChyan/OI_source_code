#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200005;
ll IT[MAXN<<2],add[MAXN<<2],a[MAXN];
char opt[1000];
int n,q;

void pushup(int rt){IT[rt]=min(IT[rt<<1],IT[rt<<1|1]);}

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

inline void pushdown(int rt)
{
	if(add[rt])
	{
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		IT[rt<<1]+=add[rt];
		IT[rt<<1|1]+=add[rt];
		add[rt]=0;
	}
}

void update(int L,int R,ll C,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		IT[rt]+=C;
		add[rt]+=C;
		return;
	}
	int m=(l+r)>>1;
	pushdown(rt);
	if(L<=m) update(L,R,C,l,m,rt<<1);
	if(R>m) update(L,R,C,m+1,r,rt<<1|1);
	pushup(rt);
}


ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return IT[rt];
	int m=(l+r)>>1;
	pushdown(rt);
	ll ANS=0x3f3f3f3f3f3f3f3fll;
	if(L<=m) ANS=min(ANS,query(L,R,l,m,rt<<1));
	if(R>m) ANS=min(ANS,query(L,R,m+1,r,rt<<1|1));
	return ANS;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n,1);
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		ll l,r,v;
		scanf(" %[^\n]",opt);
		//printf("qaq %d\n",sscanf(opt,"%lld%lld%lld",&l,&r,&v));
		if(sscanf(opt,"%lld%lld%lld",&l,&r,&v)==3)
        {
            l++;r++;
            if(l<=r) update(l,r,v,1,n,1);
            else
            {
                update(l,n,v,1,n,1);
                update(1,r,v,1,n,1);
            }
        }
        else
        {
            ll ans;
            l++;r++;
            if(l<=r) ans=query(l,r,1,n,1);
            else
            {
                ans=query(l,n,1,n,1);
                ans=min(ans,query(1,r,1,n,1));
            }
            printf("%lld\n",ans);
        }
	}

	return 0;
}

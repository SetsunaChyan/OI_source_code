#include <cstdio>
#include <memory.h>

typedef long long ll;
const int MAXN=5e5+50;
struct node
{
	int max_sub_x,max_sub_y,max_suffix_x,max_prefix_x,l,r;
	ll max_sub,max_prefix,max_suffix,sum;
}IT[MAXN<<2];
ll a[MAXN];
int n,q;

inline node pushup(node ls,node rs)
{
	node ret=ls;
	ret.l=ls.l;ret.r=rs.r;ret.sum=ls.sum+rs.sum;
	if(ret.max_sub<ls.max_suffix+rs.max_prefix)
	{
		ret.max_sub=ls.max_suffix+rs.max_prefix;
		ret.max_sub_x=ls.max_suffix_x;
		ret.max_sub_y=rs.max_prefix_x;
	}
	if(ret.max_sub<rs.max_sub)
	{
		ret.max_sub=rs.max_sub;
		ret.max_sub_x=rs.max_sub_x;
		ret.max_sub_y=rs.max_sub_y;
	}
	if(ret.max_prefix<ls.sum+rs.max_prefix)
	{
		ret.max_prefix=ls.sum+rs.max_prefix;
		ret.max_prefix_x=rs.max_prefix_x;
	}

	ret.max_suffix=ls.max_suffix+rs.sum;
	ret.max_suffix_x=ls.max_suffix_x;
	if(ret.max_suffix<rs.max_suffix)
	{
		ret.max_suffix=rs.max_suffix;
		ret.max_suffix_x=rs.max_suffix_x;
	}
	return ret;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		IT[rt].r=IT[rt].l=IT[rt].max_sub_x=IT[rt].max_sub_y=IT[rt].max_suffix_x=IT[rt].max_prefix_x=l;
		IT[rt].sum=IT[rt].max_sub=IT[rt].max_suffix=IT[rt].max_prefix=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	IT[rt]=pushup(IT[rt<<1],IT[rt<<1|1]);
}

node query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return IT[rt];
	node ret,ls,rs;
	int m=(l+r)>>1;
	if(L<=m&&m<R) ret=pushup(query(L,R,l,m,rt<<1),query(L,R,m+1,r,rt<<1|1));
	else if(m<R) ret=query(L,R,m+1,r,rt<<1|1);
	else if(L<=m) ret=query(L,R,l,m,rt<<1);
	return ret;
}

int main()
{
	int t=0;
	while(~scanf("%d%d",&n,&q))
	{
		t++;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		build(1,n,1);
		printf("Case %d:\n",t);
		for(int i=0;i<q;i++)
		{    
			int x,y;
			scanf("%d%d",&x,&y);
			node temp=query(x,y,1,n,1);
			printf("%d %d\n",temp.max_sub_x,temp.max_sub_y);
		}
	}
	return 0;
}
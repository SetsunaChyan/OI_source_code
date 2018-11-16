#include <cstdio>
#include <memory.h>

const int MAXN=1e5+50;
int IT[MAXN<<2],a[MAXN];

inline int min(int a,int b){return a<b?a:b;}

inline void pushup(int rt)
{
	IT[rt]=min(IT[rt<<1],IT[rt<<1|1]);
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		IT[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(int des,int v,int l,int r,int rt)
{
	if(l==r)
	{
		IT[rt]=v;
		return;
	}
	int m=(l+r)>>1;
	if(des<=m) update(des,v,l,m,rt<<1); else update(des,v,m+1,r,rt<<1|1);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R) return IT[rt];
	int m=(l+r)>>1,ret=0x3f3f3f3f;
	if(L<=m) ret=min(ret,query(L,R,l,m,rt<<1));
	if(R>m) ret=min(ret,query(L,R,m+1,r,rt<<1|1));
	return ret; 
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n,1);
	while(q--)
	{
		char op;
		int b[30];
		scanf(" %c",&op);
		if(op=='q')
		{
			scanf("uery(%d,%d)",&b[0],&b[1]);
			printf("%d\n",query(b[0],b[1],1,n,1));
		}
		else
		{
			scanf("hift(");
			int k=0,temp;
			while(scanf("%d%c",&b[k],&op),op==',') k++;
			temp=a[b[0]];
			for(int i=1;i<=k;i++) a[b[i-1]]=a[b[i]];
			a[b[k]]=temp;
			for(int i=0;i<=k;i++) update(b[i],a[b[i]],1,n,1);
		}
	}
	return 0;
}
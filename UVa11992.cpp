#include <cstdio>
#include <memory.h>

const int MAXN=1e6+50;
int r,c,q,st[21][MAXN<<2],add[21][MAXN<<2];
struct node
{
	int sum,max_n,min_n;
}IT[21][MAXN<<2];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

inline void pushup(int p,int rt)
{
	int ls=rt<<1,rs=rt<<1|1;
	IT[p][rt].sum=IT[p][ls].sum+IT[p][rs].sum;
	IT[p][rt].max_n=max(IT[p][ls].max_n,IT[p][rs].max_n);
	IT[p][rt].min_n=min(IT[p][ls].min_n,IT[p][rs].min_n);
}

void pushdown(int p,int rt,int ln,int rn)
{
	int ls=rt<<1,rs=rt<<1|1;
	if(st[p][rt])
	{
		IT[p][ls].sum=ln*st[p][rt];
		IT[p][rs].sum=rn*st[p][rt];
		IT[p][rs].max_n=IT[p][ls].max_n=IT[p][rs].min_n=IT[p][ls].min_n=st[p][rt];
		st[p][ls]=st[p][rs]=st[p][rt];
		add[p][ls]=add[p][rs]=0;
	}
	if(add[p][rt])
	{
		IT[p][ls].sum+=ln*add[p][rt];
		IT[p][rs].sum+=rn*add[p][rt];
		IT[p][ls].max_n+=add[p][rt];
		IT[p][ls].min_n+=add[p][rt];
		IT[p][rs].max_n+=add[p][rt];
		IT[p][rs].min_n+=add[p][rt];
		add[p][ls]+=add[p][rt];
		add[p][rs]+=add[p][rt];
	}
	st[p][rt]=0;
	add[p][rt]=0;
}

void build(int p,int l,int r,int rt)
{
	add[p][rt]=0;
	st[p][rt]=0;
	if(l==r)
	{
		IT[p][rt].sum=0;
		IT[p][rt].min_n=0;
		IT[p][rt].max_n=0;
		return;
	}
	int m=(l+r)>>1;
	build(p,l,m,rt<<1);
	build(p,m+1,r,rt<<1|1);
	pushup(p,rt);
}

void update(int p,int L,int R,int opt,int v,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		if(opt==1)
		{
			add[p][rt]+=v;
			IT[p][rt].sum+=(r-l+1)*v;
			IT[p][rt].max_n+=v;
			IT[p][rt].min_n+=v;
		}
		else
		{
			add[p][rt]=0;
			st[p][rt]=v;
			IT[p][rt].sum=(r-l+1)*v;
			IT[p][rt].max_n=IT[p][rt].min_n=v;
		}
		return;
	}
	int m=(l+r)>>1;
	pushdown(p,rt,m-l+1,r-m);
	if(L<=m) update(p,L,R,opt,v,l,m,rt<<1);
	if(R>m) update(p,L,R,opt,v,m+1,r,rt<<1|1);
	pushup(p,rt);
}

node query(int p,int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return IT[p][rt];
	int m=(l+r)>>1;
	pushdown(p,rt,m-l+1,r-m);
	node temp;
	memset(&temp,0,sizeof(temp));
	temp.min_n=2e9;
	if(L<=m)
	{
		node t=query(p,L,R,l,m,rt<<1);
		temp.max_n=max(temp.max_n,t.max_n);
		temp.min_n=min(temp.min_n,t.min_n);
		temp.sum+=t.sum;
	}
	if(R>m)
	{
		node t=query(p,L,R,m+1,r,rt<<1|1);
		temp.max_n=max(temp.max_n,t.max_n);
		temp.min_n=min(temp.min_n,t.min_n);
		temp.sum+=t.sum;
	}
	return temp;
}

int main()
{
	while(~scanf("%d%d%d",&r,&c,&q))
	{
		for(int i=1;i<=r;i++) build(i,1,c,1);
		while(q--)
		{
			int x1,y1,x2,y2,opt;
			scanf("%d%d%d%d%d",&opt,&x1,&y1,&x2,&y2);
			if(opt==3)
			{
				int maxn=0,minn=2e9,s=0;
				for(int i=x1;i<=x2;i++)
				{
					node temp=query(i,y1,y2,1,c,1);
					maxn=max(maxn,temp.max_n);
					minn=min(minn,temp.min_n);
					s+=temp.sum;
				}
				printf("%d %d %d\n",s,minn,maxn);
			}
			else
			{
				int v;
				scanf("%d",&v);
				for(int i=x1;i<=x2;i++)
					update(i,y1,y2,opt,v,1,c,1);
			}
		}
	}
	
	return 0;
}

#include <cstdio>
#include <memory.h>

const int MAXN=1e5+50;
int n,ans,IT[MAXN<<2],m[MAXN<<2],cov[MAXN<<2],l[MAXN],r[MAXN],h[MAXN],mm;

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

inline void pushup(int rt)
{
	IT[rt]=max(IT[rt<<1],IT[rt<<1|1]);
	if(cov[rt<<1]+cov[rt<<1|1]==0&&IT[rt<<1]==IT[rt<<1|1]) cov[rt]=0; else cov[rt]=1;
}

inline void pushdown(int rt)
{
	if(m[rt])
	{
		IT[rt<<1]=m[rt];
		IT[rt<<1|1]=m[rt];
		m[rt<<1|1]=m[rt];
		m[rt<<1]=m[rt];
		cov[rt<<1]=0;
		cov[rt<<1|1]=0;
		m[rt]=0;
	}
}

void update(int L,int R,int v,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		if(IT[rt]<=v)
		{
			IT[rt]=v;
			ans+=r-l+1;
			m[rt]=v;
			cov[rt]=0;
		}
		if(cov[rt]==0) return;
	}
	int m=(l+r)>>1;
	pushdown(rt);
	if(L<=m) update(L,R,v,l,m,rt<<1);
	if(R>m) update(L,R,v,m+1,r,rt<<1|1);
	pushup(rt);
}

int main()
{
	//freopen("data.in","r",stdin);
	int _;
	scanf("%d",&_);
	while(_--)
	{
		memset(m,0,sizeof(m));
		memset(IT,0,sizeof(IT));
		memset(cov,0,sizeof(cov));
		ans=0;mm=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&l[i],&r[i],&h[i]);
			mm=max(mm,r[i]);
		}
		for(int i=0;i<n;i++)
			update(l[i],r[i]-1,h[i],1,mm,1);
		printf("%d\n",ans);
	}
	return 0;
}
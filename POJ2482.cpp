#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long ll;

const ll MAXN=2e4+50;
ll cnt,maxnum[MAXN<<2],tag[MAXN<<2],n,w,h,p[MAXN],b[MAXN],ans;
struct node
{
	ll x,y1,y2,v;
}e[MAXN];

inline ll max(ll a,ll b){return a>b?a:b;}
inline bool cmp(node a,node b){return a.x<b.x||a.x==b.x&&a.v>b.v;}
inline ll find_pos(ll x){return lower_bound(b+1,b+cnt+1,x)-b;}

void dis()
{
	cnt=1;
	sort(e,e+2*n,cmp);
	sort(p,p+2*n);
	for(ll i=0;i<2*n;i++)
	{
		if(i&&p[i]!=p[i-1]) cnt++;
		b[cnt]=p[i];
	}
}

inline void pushdown(ll rt)
{
	if(tag[rt])
	{
		tag[rt<<1]+=tag[rt];
		tag[rt<<1|1]+=tag[rt];
		maxnum[rt<<1]+=tag[rt];
		maxnum[rt<<1|1]+=tag[rt];
		tag[rt]=0;
	}
}

inline void pushup(ll rt)
{
	maxnum[rt]=max(maxnum[rt<<1],maxnum[rt<<1|1]);
}

void update(ll L,ll R,ll x,ll l,ll r,ll rt)
{
	if(L<=l&&r<=R)
	{
		tag[rt]+=x;
		maxnum[rt]+=x;
		return;
	}
	pushdown(rt);
	ll mid=(l+r)>>1;
	if(L<=mid) update(L,R,x,l,mid,rt<<1);
	if(R>mid) update(L,R,x,mid+1,r,rt<<1|1);
	pushup(rt);
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data1.out","w",stdout);
	while(~scanf("%lld%lld%lld",&n,&w,&h))
	{
		w--;h--;ans=0;
		memset(maxnum,0,sizeof(maxnum));
		memset(tag,0,sizeof(tag));
		for(ll i=0;i<n;i++)
		{
			ll x,y,bri;
			scanf("%lld%lld%lld",&x,&y,&bri);
			e[2*i].x=x;
			e[2*i+1].x=x+w;
			e[2*i].y1=e[2*i+1].y1=p[2*i]=y;
			e[2*i].y2=e[2*i+1].y2=p[2*i+1]=y+h;
			e[2*i].v=bri;
			e[2*i+1].v=-bri;
		}
		dis();
		for(ll i=0;i<2*n;i++)
		{
			update(find_pos(e[i].y1),find_pos(e[i].y2),e[i].v,1,cnt,1);
			ans=max(maxnum[1],ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
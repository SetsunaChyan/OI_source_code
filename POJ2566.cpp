#include <cstdio>
#include <algorithm>

using namespace std;

const long long MAXN=1e5+50;
long long n,k,t,a[MAXN];
struct node
{
	long long pos,val;
}pre[MAXN];

inline long long max(long long a,long long b){return a>b?a:b;}
inline long long min(long long a,long long b){return a<b?a:b;}
inline long long absg(long long x){return x<0?-x:x;}

inline bool cmp(node a,node b)
{
	return a.val<b.val;
}

int main()
{
	while(scanf("%lld%lld",&n,&k),n&&k)
	{
		for(long long i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		pre[0].val=0;pre[0].pos=0;
		for(long long i=1;i<=n;i++)
		{
			pre[i].val=pre[i-1].val+a[i];
			pre[i].pos=i;
		}
		sort(pre,pre+n+1,cmp);
		while(k--)
		{
			scanf("%lld",&t);
			long long l=0,r=1,minx=-0x3f3f3f3f,minl=1,minr=n;
			while(r<=n&&l<=n)
			{
				if(absg(absg(pre[r].val-pre[l].val)-t)<absg(t-minx))
				{
					minx=absg(pre[r].val-pre[l].val);
					minl=min(pre[l].pos,pre[r].pos)+1;
					minr=max(pre[l].pos,pre[r].pos);
				}
				if(absg(pre[r].val-pre[l].val)>t&&l<r-1)
					l++;
				else 
					r++;
			}
			printf("%lld %lld %lld\n",minx,minl,minr);
		}
	}
	return 0;
}
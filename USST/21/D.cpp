#include <cstdio>

typedef long long ll;
ll t,q[300005],a[300005],n,ans=-0x3f3f3f3f;

inline ll max(ll a,ll b){return a>b?a:b;}
int main()
{
  	scanf("%lld%lld",&n,&t);
  	a[0]=0;
 	for(int i=1;i<=n;i++)
 	{
  	  	ll x;
  	  	scanf("%lld",&x);
  	  	a[i]=a[i-1]+x;
  	}
  	int head=0,end=1;
  	q[0]=0;
  	for(int i=1;i<=n;i++)
  	{
  		ans=max(ans,a[i]-a[q[head]]);
    	while(head<end&&a[q[end-1]]>a[i]) end--;
    	if(head<end&&q[head]<=i-t) head++;
    	q[end++]=i;
  	} 
  	printf("%lld",ans);
  	return 0;
}
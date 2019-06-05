#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=19260817ll;
int n,m,a[100005],vis[100005],cnt,l,r,k,x;
ll ans;

int main()
{
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    cnt=n,ans=1;
    for(int i=0;i<m;i++)
    {
    	scanf("%d%d%d%d",&l,&r,&k,&x);
    	if(!a[l+k-1])
    	{
    		if(vis[x])
    		{
    			printf("0");
    			return 0;
			}
			vis[x]++;
			a[l+k-1]=x;
			cnt--;
		}
		else if(a[l+k-1]!=x)
		{
			printf("0");
			return 0;
		}
	}
	for(int i=1;i<=cnt;i++)
		ans=ans*i%mod;
    printf("%lld",ans);
    return 0;
}

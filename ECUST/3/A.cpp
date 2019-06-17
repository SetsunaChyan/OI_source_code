#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n;
ll x,now;

int main()
{
	now=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&x);
		now=(x+now+now*x%mod)%mod;
		printf("%lld\n",now);
	}	
	return 0;
}

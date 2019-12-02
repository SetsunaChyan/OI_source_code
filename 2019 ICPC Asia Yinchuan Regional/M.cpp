#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll c[1000005];

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

int main()
{
    int _,n;
    scanf("%d",&_);
    c[0]=c[1]=1;
    for(int i=2;i<=1000000;i++)
        c[i]=c[i-1]*(4*i-2)%mod*fp(i+1,mod-2)%mod;
    while(_--)
    {
        scanf("%d",&n);
        printf("%lld\n",c[n]);
    }
	return 0;
}

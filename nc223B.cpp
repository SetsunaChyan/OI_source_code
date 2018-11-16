#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define sd(a) scanf("%d",&a)
const ll mod=1e8+7;

ll exgcd(ll a,ll b,ll &x,ll &y) { if(!b) { x=1; y=0; return a; } ll GCD=exgcd(b,a%b,x,y); ll tmp=x; x=y; y=tmp-a/b*y; return GCD; }

ll inv1(ll a,ll mod)
{
    ll x,y;
    ll d=exgcd(a,mod,x,y);
    if(d==1) return (x%mod+mod)%mod;
    return -1;
}

ll quick(ll a,ll n)
{
	ll ans=1;
	ll res=a;
	while(n)
	{
		if(n&1)ans*=res%mod;
		res*=res%mod;
		n>>=1;
	}
	return ans%mod;
}

int main()
{
	ll n,ny=inv1(8,mod);
	cin>>n;
	n++;
	cout<<((ll)((quick(4,n)-4*quick(3,n)+6*quick(2,n)-4)%mod*ny)%mod)<<endl;
	return 0;	
}
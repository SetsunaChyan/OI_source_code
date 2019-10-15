#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
map<ll,int> mp;
ll q,n;

void f(ll m,ll &x1,ll &x2,ll &x3,ll &x4)
{
	ll y1,y2,y3,y4,t1;
	if(m==0)
    {
		x1=1;x2=0;x3=0;x4=1;
		return;
	}
	if(m==1)
    {
		x1=3;x2=1;x3=2;x4=0;
		return;
	}
	f(m/2,y1,y2,y3,y4);
	x1=(y1*y1%mod+y2*y3%mod)%mod;
	x2=(y1*y2%mod+y2*y4%mod)%mod;
	x3=(y3*y1%mod+y4*y3%mod)%mod;
	x4=(y3*y2%mod+y4*y4%mod)%mod;
	if(m%2==1)
    {
		t1=(x1*3%mod+x2*2%mod)%mod;
		x2=x1;
		x1=t1;
		t1=(x3*3%mod+x4*2%mod)%mod;
		x4=x3;
		x3=t1;
	}
}

int main()
{
	ll i,a,x1,x2,x3,x4,ans=0;
	cin>>q>>n;
	for(i=1;i<=q;i++)
    {
        if(mp.find(n)!=mp.end())
            a=mp[n];
        else
        {
            if(n==0) x1=0;
            else f(n-1,x1,x2,x3,x4);
            a=x1;
            mp[n]=x1;
        }
		n=(n^(a*a));
		ans^=a;
	}
	cout<<ans<<endl;
	return 0;
}

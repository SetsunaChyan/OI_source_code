#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 int128;

const int N=10000005;
int prime[N],cnt,v[N];

int128 fp(int128 x,int128 y,int128 mod)
{
    int128 ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

void sel()
{
    int n=10000000;
    memset(v,0,sizeof(v));
    for(int i=2;i<=n;i++)
    {
        if(v[i]==0) v[i]=i,prime[cnt++]=i;
        for(int j=0;j<cnt;j++)
        {
            if(prime[j]>v[i]||prime[j]>n/i) break;
            v[i*prime[j]]=prime[j];
        }
    }
}

bool isp(ll n)
{
    for(int i=0;i<cnt;i++)
    {
        if(n==prime[i]) return true;
        if(n%prime[i]==0) return false;
    }
    return true;
}

void solve()
{
    ll x;
    scanf("%lld",&x);
    ll i;
    int128 ans=1;
    for(i=x-2;i;i-=2)
        if(isp(i)) break;
    for(i++;i<=x-2;i++)
        ans=ans*i%x;
    printf("%lld\n",(ll)fp(ans,x-2,x));
}

int main()
{
    sel();
    ll _;
    scanf("%lld",&_);
    while(_--) solve();
    return 0;
}

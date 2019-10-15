#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=0,n;
map<ll,ll> mp;

ll f(ll x)
{
    if(x==1) return 0;
    if(mp[x]) return mp[x];
    ll mid=1;
    while(mid*2<x) mid<<=1;
    return mp[x]=f(mid)+f(x-mid)+mid;
}

int main()
{
    scanf("%lld",&n);
    printf("%lld",f(n));
    return 0;
}

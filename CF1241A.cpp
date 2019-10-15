#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isp(ll x)
{
    for(ll i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}

void solve()
{
    ll n;
    scanf("%lld",&n);
    if(n==2) printf("2\n");
    else if(n&1) printf("1\n");
    else printf("0\n");
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--) solve();
    return 0;
}

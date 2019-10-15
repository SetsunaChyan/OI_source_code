#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[1005];

ll f(ll x)
{
    ll ret=0;
    while(x) ret+=x%10,x/=10;
    if(ret>=10) ret=f(ret);
    return ret;
}

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    ll now=a[n-1];
    for(int i=n-2;i>=0;i--)
        now=f((now+1)*a[i]);
    printf("%lld\n",f(now));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

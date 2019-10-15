#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,m,x,ans,l,r;

bool check(ll x)
{
    if(c-x+m-x>=x) return true;
    return false;
}

void solve()
{
    scanf("%lld%lld%lld",&c,&m,&x);
    ans=min(c,min(m,x));
    c-=ans,m-=ans;
    //ans+=min(c,m);
    l=0,r=min(c,m);
    while(l<r)
    {
        ll mid=l+r+1>>1;
        if(check(mid)) l=mid; else r=mid-1;
    }
    printf("%lld\n",ans+l);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

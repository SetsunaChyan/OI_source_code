#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
map<ll,int> cnt;

void solve()
{
    scanf("%d",&n);
    cnt.clear();
    for(int i=0;i<n;i++)
    {
        ll x;
        scanf("%lld",&x);
        cnt[x]++;
    }
    for(ll i=1;i<2048;i<<=1)
        cnt[i*2]+=cnt[i]/2;
    if(cnt[2048]>0) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

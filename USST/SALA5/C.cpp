#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q;
vector<ll> p,cnt,has;

int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=2;i*i<=q;i++)
        if(q%i==0)
        {
            p.push_back(i);
            ll qaq=0;
            while(q%i==0) q/=i,qaq++;
            cnt.push_back(qaq);
        }
    if(q!=1) p.push_back(q),cnt.push_back(1);
    for(auto pp:p)
    {
        ll now=n,qaq=0;
        while(now/pp!=0) qaq+=now/pp,now/=pp;
        has.push_back(qaq);
    }
    ll ans=0x3f3f3f3f3f3f3f3fll;
    for(int i=0;i<cnt.size();i++)
        ans=min(ans,has[i]/cnt[i]);
    printf("%lld",ans);
    return 0;
}

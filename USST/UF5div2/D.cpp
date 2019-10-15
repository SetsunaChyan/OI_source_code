#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll b1,q,l,m,ans,cnt;
set<ll> s;

bool has(ll x)
{
    return s.find(x)!=s.end();
}

int main()
{
    scanf("%lld%lld%lld%lld",&b1,&q,&l,&m);
    for(int i=0;i<m;i++)
    {
        ll x;
        scanf("%lld",&x);
        s.insert(x);
    }
    ll now=b1;
    while(abs(now)<=l)
    {
        cnt++;
        if(!has(now)) ans++;
        now*=q;
        if(cnt>=1000)
        {
            if(ans==0) printf("0");
            else if(ans==1) printf("1");
            else printf("inf");
            return 0;
        }
    }
    printf("%lld",ans);
    return 0;
}

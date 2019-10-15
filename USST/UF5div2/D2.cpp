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
    /*if(q==0&&has(0))
    {
        if(has(b1)||abs(b1)>l) printf("0");
        else printf("1");
        return 0;
    }
    else if(q==0)
    {
        printf("inf");
        return 0;
    }*/
    if(q==1)
    {
        if(has(b1)) printf("0");
        else if(abs(b1)<=l) printf("inf");
        else printf("0");
        return 0;
    }
    if(q==-1)
    {
        if(has(b1)&&has(-b1)) printf("0");
        else if(abs(b1)<=l) printf("inf");
        else printf("0");
        return 0;
    }
    ll now=b1;
    while(abs(now)<=l)
    {
        cnt++;
        if(!has(now)) ans++;
        now*=q;
        if(cnt>=1000)
        {
            printf("inf");
            return 0;
        }
    }
    printf("%lld",ans);
    return 0;
}

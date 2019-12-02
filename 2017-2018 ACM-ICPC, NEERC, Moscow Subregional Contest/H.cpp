#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll s,n,mx,mm;
int m;
pll p[100005];

ll gaomm(ll L,ll R,ll len)
{
    ll l=0,r=min(L,R),mid;
    while(l<r)
    {
        mid=l+r>>1;
        if(abs(mid-L)+abs(mid-R)>len) l=mid+1; else r=mid;
    }
    return l;
}

ll gaomx(ll L,ll R,ll len)
{
    ll l=max(L,R),r=2e10,mid;
    while(l<r)
    {
        mid=(l+r+1)>>1;
        if(abs(mid-L)+abs(mid-R)>len) r=mid-1; else l=mid;
    }
    return l;
}

int main()
{
    scanf("%lld%lld%d",&s,&n,&m);
    for(int i=0;i<m;i++)
        scanf("%lld%lld",&p[i].first,&p[i].second),mm-=p[i].second,mx-=p[i].second;
    for(int i=1;i<m;i++)
        if(abs(p[i].second-p[i-1].second)>p[i].first-p[i-1].first) return printf("No"),0;
    ll k=min(p[0].first,p[0].second+1);
    mx+=(2*p[0].second+p[0].first-1)*p[0].first/2;
    mm+=(2*p[0].second-k+1)*k/2;
    k=min(n-p[m-1].first+1,p[m-1].second+1);
    mx+=(2*p[m-1].second+n-p[m-1].first)*(n-p[m-1].first+1)/2;
    mm+=(2*p[m-1].second-k+1)*k/2;
    for(int i=1;i<m;i++)
    {
        ll a=gaomm(p[i-1].second,p[i].second,p[i].first-p[i-1].first);
        ll b=gaomx(p[i-1].second,p[i].second,p[i].first-p[i-1].first);
        mm+=(p[i-1].second+a)*(abs(p[i-1].second-a)+1)/2+(p[i].second+a)*(abs(p[i].second-a)+1)/2;
        mx+=(p[i-1].second+b)*(abs(p[i-1].second-b)+1)/2+(p[i].second+b)*(abs(p[i].second-b)+1)/2;
        if(abs(p[i-1].second-a)+abs(p[i].second-a)==p[i].first-p[i-1].first) mm-=a;
        if(abs(p[i-1].second-b)+abs(p[i].second-b)==p[i].first-p[i-1].first) mx-=b;
    }
    if(s>=mm&&s<=mx) printf("Yes\n");
    else printf("No\n");
    return 0;
}

/*
8 4 3
1 1
2 2
3 3
*/

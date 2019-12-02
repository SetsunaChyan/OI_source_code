#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x;
int a[205];

void solve()
{
    scanf("%lld",&x);
    ll san=1,t=x;
    while(san<=x) san*=3;
    int now=0;
    memset(a,0,sizeof(a));
    while(san)
    {
        a[now++]=x/san;
        x%=san;san/=3;
    }
    int cur=0;
    for(;cur<now;cur++) if(a[cur]==2) break;
    if(cur==now)
    {
        printf("%lld\n",t);
        return;
    }
    for(;cur>0;cur--) if(a[cur]==0) break;
    a[cur]=1;
    for(cur++;cur<now;cur++) a[cur]=0;
    ll ans=0,base=1;
    for(int i=now-1;i>=0;i--)
        ans+=base*a[i],base*=3;
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}


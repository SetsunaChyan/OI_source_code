#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll s,ans=1e18,a[1000005];
vector<ll> v;

ll solve(ll x)
{
    ll s=0,ret=0;
    for(int i=0;i<n;i++)
        s+=a[i],s%=x,ret+=min(s,x-s);
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i),s+=a[i];
    if(s==1) return printf("-1"),0;
    for(ll i=2;i*i<=s;i++)
        if(s%i==0)
        {
            v.push_back(i);
            while(s%i==0) s/=i;
        }
    if(s!=1) v.push_back(s);
    for(auto p:v) ans=min(ans,solve(p));
    printf("%lld",ans);
    return 0;
}

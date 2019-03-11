#include <cstdio>

typedef long long ll;
inline int f(ll x){int ret=0;for(;x;x>>=1)ret+=x&1;return ret;}
inline ll lowbit(ll x){return x&-x;}

int main()
{
    ll n,k,ans=0;
    scanf("%lld%lld",&n,&k);
    while(f(n)>k){ans+=lowbit(n);n+=lowbit(n);}
    printf("%lld",ans);
    return 0;
}
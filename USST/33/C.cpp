#include <cstdio>
#include <memory.h>

typedef long long ll;
ll n,m,k,x,loop[1000005],r,cnt[1000005];

ll fp(ll x)
{
    ll ret=1,base=10;
    while(x)
    {
        if(x&1) ret=ret*base%n;
        base=base*base%n;
        x>>=1;
    }
    return ret%n;
}

int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    m%=n;
    printf("%lld",(x+fp(k)*m%n)%n);
    return 0;
}
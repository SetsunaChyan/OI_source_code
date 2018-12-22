#include <cstdio>

typedef long long ll;
ll x,n,s,m=2e12,sum=0;

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    scanf("%lld%lld",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        sum+=x;
        m=min(m,x);
    }
    if(sum-s<0)
        printf("-1");
    else
        printf("%lld",min(m,(sum-s)/n));
    return 0;
}
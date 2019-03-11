#include <cstdio>
#include <memory.h>
#include <algorithm>

typedef long long ll;
ll t,n,dp[100005],a[55],b[55],c[55],ans=0;

struct node
{
    ll a,b,c;
}e[55];

inline ll max(ll a,ll b){return a>b?a:b;}
//a[x]-t*b[x]+a[y]-(t+c[x])*b[y]>a[y]-t*b[y]+a[x]-(t+c[y])*b[x]
//-c[x]*b[y]>-c[y]*b[x]
inline bool cmp(node x,node y){return x.c*y.b<y.c*x.b;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%lld%lld",&t,&n);
    for(int i=0;i<n;i++) scanf("%lld",&e[i].a);
    for(int i=0;i<n;i++) scanf("%lld",&e[i].b);
    for(int i=0;i<n;i++) scanf("%lld",&e[i].c);
    std::sort(e,e+n,cmp);
    for(int i=0;i<n;i++)
        for(ll j=t;j>=e[i].c;j--)
            dp[j]=max(dp[j-e[i].c]+e[i].a-j*e[i].b,dp[j]);
    for(int i=0;i<=t;i++)
        ans=max(ans,dp[i]);
    printf("%lld",ans);
    return 0;
}
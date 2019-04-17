#include <cstdio>

typedef long long ll;

ll n,m,k,a,b,c,ans;

inline ll min(ll a,ll b){return a<b?a:b;}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&a,&b,&c);
        ans=0x3f3f3f3f3f3f3f3fll;
        for(int i=0;i<=k;i++)
        {
            ll tmp=(k-i)*c,g=0x3f3f3f3f3f3f3f3fll,h=0x3f3f3f3f3f3f3f3fll;
            for(int j=0;j*2<=n+i+1;j++)
                g=min(g,a*j+(n+i-2*j+2)/3*b);
            for(int j=0;j*2<=m+i+1;j++)
                h=min(h,a*j+(m+i-2*j+2)/3*b);
            ans=min(tmp+g+h,ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
#include <cstdio>

typedef long long ll;
ll n,h,w,x,y,ans=0;

int main()
{
    scanf("%lld%lld%lld",&n,&h,&w);
    while(n--)
    {
        scanf("%lld%lld",&x,&y);
        ans+=x>=h&&y>=w;
    }
    printf("%lld",ans);
    return 0;
}
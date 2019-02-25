#include <cstdio>

typedef long long ll;
ll l,r,k,m,l1,r1;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld%lld%lld",&l,&r,&k,&m);
        l--;
        l1=l,r1=r;
        ll t=m;
        while(t)
        {
            t--;
            r/=k;
        }
        r1=r/k;
        t=m;
        while(t)
        {
            t--;
            l/=k;
        }
        l1=l/k;
        printf("%lld\n",r-l-r1+l1);
    }
    return 0;  
}
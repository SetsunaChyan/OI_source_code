#include <cstdio>

int main()
{
    long long n,m,p,t=0,ans=0;
    scanf("%lld%lld",&n,&m);
    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&p);
        t+=p;
        if(t>m)
        {
            t=p;
            ans++;
        }
    }
    printf("%lld",ans+1);
    return 0;
}

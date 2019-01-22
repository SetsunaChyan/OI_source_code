#include <cstdio>

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        long long n,t=0;
        scanf("%lld",&n);
        n--;
        while(n)
        {
            t+=n&1;
            n>>=1;
        }
        printf("%lld\n",1ll<<t);
    }
    return 0;
}
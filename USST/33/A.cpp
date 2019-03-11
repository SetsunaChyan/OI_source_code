#include <cstdio>

int main()
{
    long long a,b,n;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",a*b-1);
    }
    return 0;
}
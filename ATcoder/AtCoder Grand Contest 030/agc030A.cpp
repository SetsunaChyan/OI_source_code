#include <cstdio>

typedef long long ll;
ll a,b,c;

int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a+b>=c)
        printf("%lld",b+c);
    else
        printf("%lld",a+b+b+1);
    return 0;
}
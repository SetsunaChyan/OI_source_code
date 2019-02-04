#include <cstdio>

long long n;

int main()
{
    scanf("%lld",&n);
    n=(n+1)*n/2;
    printf("%d",n&1);
    return 0;
}
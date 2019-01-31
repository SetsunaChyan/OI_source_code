#include <cstdio>

long long n;

int main()
{
    scanf("%lld",&n);
    if(n==1)
        printf("1");
    else if(n==2)
        printf("2");
    else if(n==3)
        printf("6");
    else if(n&1)
        printf("%lld",n*(n-1)*(n-2));
    else if(n%3)
        printf("%lld",(n-1)*(n-3)*n);
    else
        printf("%lld",(n-1)*(n-2)*(n-3));
    return 0;
}
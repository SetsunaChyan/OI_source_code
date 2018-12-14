#include <cstdio>

int main()
{
    long long n;
    while(~scanf("%lld",&n))
    {
        if(n<4)
            printf("0\n");
        else
            printf("%lld\n",(n-1)*(n-2)*(n-3)/2/3);
    }
    return 0;
}
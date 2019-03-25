#include <cstdio>

typedef long long ll;
ll s;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld",&s);
        printf("8%07lld\n",s%10000000ll);
    }

    return 0;
}
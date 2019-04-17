#include <cstdio>

int m,s;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%*d-%*d-%*d %*d:%d:%d",&m,&s);
        printf("%d\n",(60*60-m*60-s)%100);
    }
    return 0;
}
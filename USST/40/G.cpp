#include <cstdio>

int a,b;
char c;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%o%c%o",&a,&c,&b);
        if(c=='+') a=a+b; else a=a-b;
        printf("%x\n",a);
    }
    return 0;
}
#include <cstdio>

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",x%7?x/7+1:x/7);
    }
    return 0;
}
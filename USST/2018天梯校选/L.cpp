#include <cstdio>

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b)&&a&&b)
        (a-1)%(b+1)?printf("sorahjy\n"):printf("king\n");
    return 0;
}
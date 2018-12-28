#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d %d\n",x,x*2);
    }
    return 0;
}
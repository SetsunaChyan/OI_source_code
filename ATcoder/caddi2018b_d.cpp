#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(x&1)
        {
            printf("first");
            return 0;
        }
    }
    printf("second");
    return 0;
}
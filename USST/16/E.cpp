#include <cstdio>

int main()
{
    int x;
    while(~scanf("%d",&x))
    {
        if(x&1)
            printf("0\n");
        else
            printf("1\n");
    }
}
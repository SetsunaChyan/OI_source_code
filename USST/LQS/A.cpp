#include <cstdio>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(b<0)
    {
        printf("%d%d=%d\n",a,b,a+b);
        printf("%d+%d=%d\n",a,-b,a-b);
        printf("%d*(%d)=%d\n",a,b,a*b);
        printf("%d/(%d)=%d\n",a,b,a/b);
    }
    else
    {
        printf("%d+%d=%d\n",a,b,a+b);
        printf("%d-%d=%d\n",a,b,a-b);
        printf("%d*%d=%d\n",a,b,a*b);
        printf("%d/%d=%d\n",a,b,a/b);
    }


    return 0;
}
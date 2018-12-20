#include <cstdio>

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int k=a/b;
        for(int i=b;i>=1;i--)
        {
            for(int j=0;j<k&&a;j++)
            {
                a--;
                printf("%c",'a'+i-1);
            }
        }
        while(a--)
            printf("a");
        printf("\n");
    }
    return 0;
}
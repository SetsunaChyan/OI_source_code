#include <cstdio>

char x;
int n;

int main()
{
    while(~scanf("%c",&x)&&x!='@')
    {
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
                printf(" ");
            printf("%c",x);
            for(int j=0;j<2*i-1;j++)
                printf(" ");
            if(i!=0) printf("%c",x);
            printf("\n");
        }
        for(int i=0;i<2*n-1;i++)
            printf("%c",x);
        printf("\n\n");      
        scanf(" ");
    }
    return 0;
}
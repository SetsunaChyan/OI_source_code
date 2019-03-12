#include <cstdio>

int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t=i,x=i;
        while(x)
        {
            t+=x%10;
            x/=10;
        }
        if(t==n)
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("no");
    return 0;
}
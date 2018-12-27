#include <cstdio>

int n,k;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=k-1;i>=1;i--)
    {
        if(n%i) continue;
        printf("%d",n/i*k+i);
        break;
    }
    return 0;
}
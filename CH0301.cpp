#include <cstdio>

int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<1<<n;i++)
    {
        int k=i,g=1;
        while(k)
        {
            if(k&1) printf("%d ",g);
            g++;
            k>>=1;
        }
        printf("\n");
    }
    return 0;
}

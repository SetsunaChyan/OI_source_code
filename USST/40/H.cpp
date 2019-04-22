#include <cstdio>

int n;

int main()
{
    scanf("%d",&n);
    int dlt=3,hd=0;
    for(int i=0;i<n;i++)
        hd+=dlt,dlt+=4;
    if(hd+2*n>=10000)
    {
        printf("No");
        return 0;
    }
    for(int i=0;i<=n;i++) printf("%d ",hd+i);
    for(int i=n+1;i<2*n;i++) printf("%d ",hd+i);
    printf("%d",hd+2*n);
    return 0;
}
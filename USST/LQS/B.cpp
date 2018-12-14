#include <cstdio>
#include <memory.h>

int a[20001],maxn=-1,g=-1;

int main()
{
    memset(a,0,sizeof(a));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
        if(a[x]>maxn)
        {
            g=x;
            maxn=a[x];
        }
    }
    printf("%d %d",g,maxn);
    return 0;
}
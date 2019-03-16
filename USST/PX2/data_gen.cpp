#include <cstdio>
#include <time.h>
#include <cstdlib>

int a[1000];

void shuffle(int q)
{
    for(int i=0;i<q;i++)
    {
        int x=rand()%q,y=rand()%q,t=a[x];
        a[x]=a[y],a[y]=t;
    }
}

int main()
{
    freopen("data.in","w",stdout);
    srand(time(NULL));
    for(int i=1;i<=1000;i++) a[i-1]=i;
    printf("30\n");
    for(int i=0;i<30;i++)
    {
        printf("1000\n");
        shuffle(1000);
        for(int j=0;j<1000;j++)
            printf("%d ",a[j]);
        printf("\n");
    }
    return 0;
}
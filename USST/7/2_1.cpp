#include<stdio.h>
int main()
{
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    long a[1001];
     int i,j;
    for(i=0;i<1001;i++)
    a[i]=0;
    a[1]=1;
    a[2]=2;
    a[3]=2;

    for(i=4;i<=1000;i++)
    {
        for(j=1;j<=i/2;j++)
        a[i]=a[i]+a[j];
        a[i]=a[i]+1;
    }
    int n;
    while(~scanf("%d",&n))
        printf("%ld\n",a[n]);
}

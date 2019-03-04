#include <cstdio>

int f[200001],sum[200001];

int main()
{
    int j,n,x,max;

    scanf("%d",&n);
    sum[0]=0;max=-2147483648;
    for(j=1;j<=n;j++)
    {
        scanf("%d",&x);
        sum[j]=sum[j-1]+x;
    }
    x=0;f[0]=sum[0];
    f[1]=sum[1];
    for(j=2;j<=n;j++)
    {
        if(sum[j]<sum[x])
        {
            f[j]=sum[j]-sum[j-1];
            x=j;
        }
        else
            f[j]=sum[j]-sum[x];
    }
    for(j=1;j<=n;j++)
        if(max<f[j])
            max=f[j];
    printf("%d\n",max);

    return 0;
}


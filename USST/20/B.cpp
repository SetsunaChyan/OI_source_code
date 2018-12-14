#include <cstdio>

long long f[110];

int main()
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=100;i++)
        f[i]=f[i-2]+f[i-1];
    int n;
    scanf("%d",&n);
    printf("%lld",f[n]);
    return 0;
}
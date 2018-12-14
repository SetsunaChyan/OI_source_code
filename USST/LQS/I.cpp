#include <cstdio>
#include <memory.h>

long long f[100];

int main()
{
    memset(f,0,sizeof(f));
    int a,b;
    scanf("%d%d",&a,&b);
    f[a]=1;
    for(int i=a;i<=b;i++)
    {
        f[i+2]+=f[i];
        f[i+1]+=f[i];
    }
    printf("%lld",f[b]);
    return 0;
}
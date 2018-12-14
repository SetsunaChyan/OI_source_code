#include <cstdio>

int n;

int main()
{
    long long ans=0;
    int now=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(now<x) ans+=x-now;
        now=x;
    }
    printf("%lld",ans);

    return 0;
}
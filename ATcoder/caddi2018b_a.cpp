#include <cstdio>

int ans=0,p;

int main()
{
    scanf("%d",&p);
    while(p)
    {
        if(p%10==2) ans++;
        p/=10;
    }
    printf("%d",ans);
    return 0;
}
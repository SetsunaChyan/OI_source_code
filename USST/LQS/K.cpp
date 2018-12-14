#include <cstdio>

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    int a,b,c,d;
    double ans=1.0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int t=max(a,c);
    for(int i=1;i<=t;i++)
    {
        if(i<=b) ans/=i;
        if(i<=d) ans*=i;
        if(i<=c) ans/=i;
        if(i<=a) ans*=i;
        if(i<=a-b) ans/=i;
        if(i<=c-d) ans*=i;
    }
    printf("%.5lf",ans);
    return 0;
}
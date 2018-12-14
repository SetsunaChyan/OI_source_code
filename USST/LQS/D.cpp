#include <cstdio>
#include <cmath>

double h,k,r,ans;

inline double min(double a,double b){return a<b?a:b;}

int main()
{
    scanf("%lf%lf%lf",&h,&k,&r);
    if(h<=k)
    {
        ans=r;
    }
    else
    {
        ans=sqrt((h-k)*(h-k)+r*r);
    }
    printf("%.3lf",round(ans*1000.0)/1000.0);
    return 0;
}
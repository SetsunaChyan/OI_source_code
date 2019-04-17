#include <cstdio>
#include <cmath>

double r,R,n;

int main()
{
    int cnt=0;
    scanf("%lf%lf%lf",&R,&r,&n);
    for(int i=0;i<n;i++)
    {
        double x,y,d,t;
        scanf("%lf%lf%lf",&x,&y,&d);
        t=sqrt(x*x+y*y);
        if(t+d<=R&&t-d>=R-r) cnt++;
    }
    printf("%d",cnt);
    return 0;
}
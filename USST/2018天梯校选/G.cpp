#include <cstdio>
#include <cmath>

struct node
{
    double x,y;
}p[105];
double ans=1e30;
int n;

inline double min(double a,double b){return a<b?a:b;}
inline void swap(double &a,double &b){double t=a;a=b;b=t;}

double f(double x1,double y1,double x2,double y2,double x3,double y3)
{
    if(y1==y3)
    {
        swap(x1,y1);
        swap(x2,y2);
        swap(x3,y3);
    }
    double b=(x3-x1)/(y1-y3);
    double c=-b*y1-x1;
    return fabs(0.5*(x2+b*y2+c)/sqrt(1+b*b));
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int i=0;i<n;i++)
        ans=min(ans,f(p[i].x,p[i].y,p[(i+1)%n].x,p[(i+1)%n].y,p[(i+2)%n].x,p[(i+2)%n].y));
    printf("%.6lf",ans);
    return 0;
}
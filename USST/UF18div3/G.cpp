#include <bits/stdc++.h>
using namespace std;

double x1,y1,R,x2,y2;

int main()
{
    scanf("%lf%lf%lf%lf%lf",&R,&x1,&y1,&x2,&y2);
    double dis=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if(dis>R) return printf("%.10f %.10f %.10f",x1,y1,R),0;
    double r=(dis+R)/2,x,y;
    if(dis==0) x=x1+r,y=y1;
    else x=x2+(x1-x2)*r/dis,y=y2+(y1-y2)*r/dis;
    printf("%.10f %.10f %.10f",x,y,r);
    return 0;
}

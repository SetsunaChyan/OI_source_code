#include <cstdio>
#include <algorithm>
using namespace std;

double eps = 1e-8;
struct Point {double x,y;};

bool between(double X, double X1, double X2) {return X >= min(X1, X2) && X <= max(X1, X2);}

bool detectIntersect(Point p1, Point p2, Point p3, Point p4, double &line_x, double &line_y)
{
    if ((fabs(p1.x-p2.x)<eps)&&(fabs(p3.x-p4.x)<eps))
    {
        return false;
    }
    else if ((fabs(p1.x-p2.x)<eps))
    {
        if (between(p1.x, p3.x, p4.x))
        {
            double k = (p4.y-p3.y)/(p4.x-p3.x);
            line_x = p1.x;
            line_y = k*(line_x-p3.x) + p3.y;

            if (between(line_y,p1.y,p2.y))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if((fabs(p3.x-p4.x)<eps)) //如果直线段p3p4垂直于y轴
    {
        if (between(p3.x,p1.x,p2.x))
        {
            double k = (p2.y-p1.y)/(p2.x-p1.x);
            line_x = p3.x;
            line_y = k*(line_x-p2.x) + p2.y;
            if (between(line_y, p3.y, p4.y))
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
    {
        double k1 = (p2.y-p1.y)/(p2.x-p1.x);
        double k2 = (p4.y-p3.y)/(p4.x-p3.x);

        if (fabs(k1-k2) < eps)
            return false;
        else
        {
            line_x = ((p3.y - p1.y) - (k2*p3.x - k1*p1.x)) / (k1 - k2);
            line_y = k1*(line_x-p1.x) + p1.y;
        }

        if (between(line_x, p1.x, p2.x) && between(line_x, p3.x, p4.x))
            return true;
        else
            return false;
    }
}

void solve()
{
    Point p1, p2, p3, p4;
    double x, y;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
    int ok=detectIntersect(p1, p2, p3, p4, x, y);
    if(ok)
    {
        double fy=max(min(p1.y,p2.y),min(p3.y,p4.y));
        double x1=p1.x+(p1.x-p2.x)/(p1.y-p2.y)*(fy-p1.y);
        double x2=p3.x+(p3.x-p4.x)/(p3.y-p4.y)*(fy-p3.y);
        double s=0.5*fabs(y-fy)*fabs(x1-x2);
        fy=min(max(p1.y,p2.y),max(p3.y,p4.y));
        x1=p1.x+(p1.x-p2.x)/(p1.y-p2.y)*(fy-p1.y);
        x2=p3.x+(p3.x-p4.x)/(p3.y-p4.y)*(fy-p3.y);
        s+=0.5*fabs(y-fy)*fabs(x1-x2);
        printf("%.2f\n",s);
    }
    else
        printf("0.00\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

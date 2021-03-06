#include <bits/stdc++.h>
using namespace std;
const double eps=1e-12;

/*
    调用 asr(l,r,simpson(l,r))
*/

inline double f(double x)
{
    return x; //被积函数
}

double simpson(double l,double r)
{
    double mid=(l+r)/2;
    return (f(l)+4*f(mid)+f(r))*(r-l)/6;
}

double asr(double l,double r,double ans)
{
    double mid=(l+r)/2;
    double l1=simpson(l,mid),r1=simpson(mid,r);
    if(fabs(l1+r1-ans)<eps) return l1+r1;
    return asr(l,mid,l1)+asr(mid,r,r1);
}

int main()
{

    return 0;
}

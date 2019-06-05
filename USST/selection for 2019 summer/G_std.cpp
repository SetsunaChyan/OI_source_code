#include <bits/stdc++.h>
#define y1 __y1__
using namespace std;

const double PI=3.14159265358979;
double x1,y1,r,x2,y2,R,s,S;
 
void solve()
{
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r,&x2,&y2,&R);
	double l=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	s=PI*r*r;S=PI*R*R;
	if(r+R<=l)
	{
		printf("0.0000\n");
		return;
	}
	if(l+R<=r)
	{
		printf("%.4lf\n",S/s);
		return;
	}
	if(l+r<=R)
	{
		printf("1.0000\n");
		return;
	}
	double p=(l+r+R)/2.0;
	double scross=-2*sqrt(p*(p-r)*(p-R)*(p-l));
	double h=-scross/l;
	scross+=asin(h/r)*r*r;
	scross+=asin(h/R)*R*R;
	printf("%.4lf\n",scross/s);
}
 
int main()
{
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}

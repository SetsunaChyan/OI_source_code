#include <cstdio>

double ans=0;

inline double max(double a,double b){return a>b?a:b;}
inline double min(double a,double b){return a<b?a:b;}

int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);	
	ans=max(min(a/3,b),min(a,b/3));
	ans=max(ans,min(a/2,b/2));
	printf("%.10lf",ans);
	return 0;
}
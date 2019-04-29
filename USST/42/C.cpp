#include <bits/stdc++.h>
using namespace std;

const double eps=1e-5;
int n,m;
double l,r,a[20005];

bool check(double x)
{
	int ret=0;
	for(int i=0;i<n;i++)
		ret+=a[i]/x;
	return ret>=m;
}

int main()
{
	l=0,r=1000000.0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lf",&a[i]);
	while(fabs(r-l)>eps)
	{
		double mid=(l+r)/2;
		if(check(mid)) l=mid; else r=mid;
	}
	int ans=r*10;
	printf("%.1lf",ans/10.0);
	return 0;
}
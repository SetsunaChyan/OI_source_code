#include <cstdio>

const int MAXN=1e5+50;
double a[MAXN],pre[MAXN],l=-2e9,r=2e9;
int n,f;

double min(double a,double b){return a<b?a:b;}

bool check(double x)
{
	double m=1e10;
	pre[0]=0;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i]-x;
	for(int i=f;i<=n;i++)
	{
		m=min(m,pre[i-f]);
		if(pre[i]-m>=0) return true; 
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&f);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	while(r-l>=1e-7)
	{
		double mid=(l+r)/2.0;
		if(check(mid)) l=mid; else r=mid;
	}
	printf("%d",int(1000.0*r));
	return 0;
}
/*
10 5
321
314
1321
214
1232
1231
1232
432
688
3
*/
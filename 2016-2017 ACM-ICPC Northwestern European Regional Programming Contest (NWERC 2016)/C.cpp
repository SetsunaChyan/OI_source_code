#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double x,y,f;
int n,l,r;

int main()
{
	scanf("%lf%lf",&x,&y);
	scanf("%d",&n);
	double sum=0.0,tmp=0.0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%lf",&l,&r,&f);
		sum+=(r-l)*f;
		tmp+=r-l;
	}
	sum+=y-tmp;
	printf("%.10lf",x/sum);
	return 0;
}

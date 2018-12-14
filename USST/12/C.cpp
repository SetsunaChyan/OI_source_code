#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps=1e-3;
int n,v,c,tot=0,sum=0,ans=0,pp[100050],a[100050],b[100050];

inline bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	scanf("%d%d%d",&n,&v,&c);
	for(int i=0;i<n;i++) {scanf("%d",&a[i]);sum+=a[i];}
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
	{
		if(!b[i])
			pp[tot++]=a[i];
	}
	sort(pp,pp+tot,cmp);
	double now=(double)v*a[0]/sum;
	for(int i=0;i<tot&&now<c;i++)
	{
		ans++;
		sum-=pp[i];
		now=(double)v*a[0]/sum;
	}
	printf("%d",ans);
	return 0;
}
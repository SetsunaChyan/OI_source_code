#include <cstdio>
#include <memory.h>
#include <cmath>

const double pi=3.14159265358979;
int n,vis[11];
double tx1,ty1,tx2,ty2,x[11],y[11],r[11],ans=0;

inline double abs(double x){return x<0?-x:x;}
inline double min(double a,double b){return a<b?a:b;}
inline double max(double a,double b){return a>b?a:b;}

void dfs(int dep,double sum)
{
	if(dep==n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]) continue; 
		double rr=min(abs(tx1-x[i]),abs(tx2-x[i]));
		rr=min(rr,abs(ty1-y[i]));
		rr=min(rr,abs(ty2-y[i]));
		for(int j=0;j<n;j++)
			if(vis[j])
				rr=min(rr,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[j]);
		if(rr<0) continue;
		r[i]=rr;
		vis[i]=1;
		dfs(dep+1,sum+pi*rr*rr);
		vis[i]=0;
	}	
}

int main()
{
	memset(r,0,sizeof(r));
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	scanf("%lf%lf%lf%lf",&tx1,&ty1,&tx2,&ty2);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	dfs(0,0);
	printf("%.0lf",abs(tx1-tx2)*abs(ty1-ty2)-ans);
	return 0;
}
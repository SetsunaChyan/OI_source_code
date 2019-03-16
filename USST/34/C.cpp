#include <cstdio>
#include <memory.h>

double dp[10005];
int n,m;

inline double max(double a,double b) {return a>b?a:b;}

int main()
{
	while(~scanf("%d%d",&m,&n)&&n&&m)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			int x;double y;
			scanf("%d%lf",&x,&y);
			for(int j=m;j>=x;j--)
				dp[j]=max(dp[j-x]+(1-dp[j-x])*y,dp[j]);
		}
		printf("%.1lf%%\n",dp[m]*100);
	}
	return 0;
}
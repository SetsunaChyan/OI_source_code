#include <cstdio>
#include <memory.h>

int dp[1005],m,n,a[1005],maxx,num;

inline int max(int a,int b){return a>b?a:b;}

void fdp()
{
	for(int i=0;i<n;i++)
		for(int j=m;j>=a[i];j--)
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
}

int main()
{
	while(~scanf("%d",&n)&&n)
	{
		maxx=-1;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>maxx)
			{
				maxx=a[i];
				num=i;
			}
		}
		scanf("%d",&m);
		if(m>=5)
		{
			a[num]=0;
			fdp();
			printf("%d\n",m-dp[m-5]-maxx);
		}
		else printf("%d\n",m);
	}
	return 0;
}

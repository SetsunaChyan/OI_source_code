#include <cstdio>

int n;
double ans=0,p[21];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf",&p[i]);
	for(int i=1;i<(1<<n);i++)
	{
		int t=i,cnt=0;
		double pp=0;
		for(int j=0;j<n;j++)
		{
			int k=t&1;
			cnt+=k;
			if(k) pp+=p[j];
			t>>=1;
		}
		if(cnt%2)
			ans+=1/pp;
		else
			ans-=1/pp;
	}
	printf("%.5lf",ans);
	return 0;
}
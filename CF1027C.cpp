#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000005],n;

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int s1,s2;
		double q=1e32;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				int j=i+2;
				while(j<=n)
					if(a[j]==a[j-1]) break; else j++;
				if(j>=n) break;
				if((double)a[j]/a[i]<q)
				{
					q=(double)a[j]/a[i];
					s1=a[i];
					s2=a[j];
				}
			}
		}
		printf("%d %d %d %d\n",s1,s1,s2,s2);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[20005],b[20005],ans,q,flag;

int main()
{
	while(~scanf("%d%d",&n,&m),n&&m)
	{
		ans=0;
		q=0;flag=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		for(int i=0;i<n;i++)
		{
			while(q<m&&a[i]>b[q]) q++;
			if(q>=m) {flag=1;break;}
			ans+=b[q];
			q++;
		}
		if(flag)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
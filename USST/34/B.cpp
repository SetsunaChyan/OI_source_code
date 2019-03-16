#include <cstdio>

int n,m,k,ans,cnt,a[100];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)
		scanf("%d",&a[i]);
	for(int now=min(n,10000);now>=0;now--)
	{
		ans=0;
		cnt=0;
		for(int i=0;i<k;i++)
		{
			if(cnt<m&&ans+a[i]<=now)
			{
				ans+=a[i];
				cnt++;
			}
			if(cnt==m) 
			{
				printf("%d",ans);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
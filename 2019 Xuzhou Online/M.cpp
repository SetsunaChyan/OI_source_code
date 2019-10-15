#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[1000005],b[1000005];
int p[1000005],k[26];
int main()
{
	scanf("%d%d%s%s",&n,&m,a,b);
	int c=0,d=0;
	while(c<n&&d<m)
	{
		if(a[c]==b[d])
		{
			p[d]=c;
			++c,++d;
		}
		else
			++c;
	}
	int up=m;
	if(c==n)
		up=d;
//	for(int i=0;i<up;i++)
//		printf("%d %d\n",i,p[i]);
	int ans=-1,now=n-1;
	for(int i=0;i<26;i++)
		k[i]=1e9;
	for(int i=up-1;i>=0;i--)
	{
		while(now>p[i])
			k[a[now]-'a']=min(k[a[now]-'a'],now),--now;
//		printf("now %d\n",now);
//		for(int j=0;j<4;j++)
//			printf("%c %d\n",'a'+j,k[j]);
		for(int j=(i+1==m?'a':b[i+1]+1);j<='z';j++)
			ans=max(ans,i+1+(n-k[j-'a']));
		//printf("ans %d\n",ans);
	}
	for(int i=0;i<n;i++)
		if(a[i]>b[0])
		{
			ans=max(ans,n-i);
			break;
		}
	printf("%d\n",ans);
	return 0;
}

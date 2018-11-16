#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
	int a,b;
}e[10005];
int n,ans,last,pre[10005],t=0;

inline bool cmp(node a,node b)
{
	return a.b>b.b;
}

inline int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	while(scanf("%d",&n),n)
	{
		t++;
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&e[i].a,&e[i].b);
			ans+=e[i].a;
		}
		sort(e,e+n,cmp);
		pre[n]=0;last=0;
		for(int i=n-1;i>=0;i--)
			pre[i]=pre[i+1]+e[i].a;
		for(int i=0;i<n;i++)
			last=max(last,e[i].b-pre[i+1]);
		printf("Case %d: %d\n",t,ans+last);
	}
	return 0;
}
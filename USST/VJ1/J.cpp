#include <cstdio>
#include <memory.h>
#include <algorithm>

int n,m,k,a[55][55];
struct node
{
	int p,cnt;
}q[55*55];

inline bool cmp(node a,node b) {return a.cnt>b.cnt;}

void solve(int cs)
{
	int flag=0;
	memset(a,0,sizeof(a));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&q[i].cnt);
		if(q[i].cnt>(n*m+1)/2) flag=1;
		q[i].p=i+1;
	}
	std::sort(q,q+k,cmp);
	printf("Case #%d:\n",cs);
	if(flag)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	int now=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if((i+j)%2==0) 
			{
				a[i][j]=q[now].p;
				q[now].cnt--;
				if(q[now].cnt==0) now++;
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if((i+j)&1) 
			{
				a[i][j]=q[now].p;
				q[now].cnt--;
				if(q[now].cnt==0) now++;
			}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m-1;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][m-1]);
	}		
}

int main()
{
	int _;
	scanf("%d",&_);
	for(int i=1;i<=_;i++) solve(i);	
	return 0;
} 

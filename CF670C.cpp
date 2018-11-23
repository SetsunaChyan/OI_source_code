#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int n,p[200050],a[200050],s[200050],h1[200050],h2[200050],m1=-1,m2=-1,tot,ans=0;

inline int find(int x){return lower_bound(p,p+tot+1,x)-p;}

int main()
{
	memset(s,0,sizeof(s));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	tot=0;
	for(int i=0;i<n;i++)
		if(!i||a[i-1]!=a[i]) p[tot++]=a[i];
    p[tot]=2e9;
	for(int i=0;i<n;i++)
		s[find(a[i])]++;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&h1[i]);
	for(int i=0;i<n;i++) scanf("%d",&h2[i]);
	for(int i=0;i<n;i++)
	{
		int x=find(h1[i]),y=find(h2[i]);
		if(p[x]!=h1[i]) x=0; else x=s[x];
		if(p[y]!=h2[i]) y=0; else y=s[y];
		if(x>m1) m1=x,m2=y,ans=i;
		else if(x==m1&&m2<y) m2=y,ans=i;
	}
	printf("%d",ans+1);
	return 0;
}
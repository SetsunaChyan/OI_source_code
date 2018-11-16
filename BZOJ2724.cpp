#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN=4e4+50;
const int MAXT=2e2+50;
int t,n,m,L[MAXN],R[MAXN],a[MAXN],b[MAXN],cnt,pre[MAXT][MAXT];

struct node
{
	int pos,v;
}e[MAXN];

inline bool cmp(node a,node b)
{
	return a.v<b.v;
}

void dis()
{
	cnt=0;
	sort(e,e+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(i&&e[i].v!=e[i-1].v) cnt++;
		b[cnt]=e[i].v;
		a[e[i].pos]=cnt;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&e[i].v);
		e[i].pos=i;
	}
	t=sqrt(n);
	
	return 0;	
}
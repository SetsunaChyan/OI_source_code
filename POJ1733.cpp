#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=5050;
int k=0,n,m,p[MAXN*2],b[MAXN*2],cnt,fa[MAXN*4];
struct node
{
	int a,b;
	char opt[10];
}e[MAXN];

inline int find_pos(int x)
{
	return lower_bound(b,b+cnt+1,x)-b+1;
}

void dis()
{
	cnt=0;
	sort(p,p+2*m);
	for(int i=0;i<2*m;i++)
	{
		if(i&&p[i]!=p[i-1]) cnt++;
		b[cnt]=p[i];
	}
	for(int i=0;i<m;i++)
	{
		e[i].a=find_pos(e[i].a);
		e[i].b=find_pos(e[i].b);
	}
}

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void Union(int x,int y)
{
	fa[find(x)]=find(y);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<MAXN*4;i++)
		fa[i]=i;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%s",&e[i].a,&e[i].b,e[i].opt);
		p[2*i]=e[i].a;
		p[2*i+1]=e[i].b;
	}
	dis();
	for(int i=0;i<m;i++)
	{
		int x=e[i].a-1,y=e[i].b;
		if(e[i].opt[0]=='e')
		{
			if(find(x)==find(2*MAXN+y)) k=i;
			Union(x,y);
			Union(2*MAXN+x,2*MAXN+y);
		}
		else
		{
			if(find(x)==find(y)) k=i;
			Union(x,2*MAXN+y);
			Union(y,2*MAXN+x);
		}
		if(k) break;
	}
	if(k)
		printf("%d\n",k);
	else
		printf("%d\n",m);
	return 0;
}
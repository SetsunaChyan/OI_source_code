#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=100050;
int fa[MAXN*2],n,p[MAXN*2],b[MAXN*2],cnt,flag;
struct node
{
	int a,b,c;
}e[MAXN];

inline int findpos(int x)
{
	return lower_bound(b,b+cnt+1,x)-b;
}

void dis()
{
	cnt=0;
	sort(p,p+2*n);
	for(int i=0;i<2*n;i++)
	{
		if(i&&p[i]!=p[i-1]) cnt++;
		b[cnt]=p[i];
	}
	for(int i=0;i<n;i++)
	{
		e[i].a=findpos(e[i].a);
		e[i].b=findpos(e[i].b);
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
	int _;
	scanf("%d",&_);
	while(_--)
	{
		flag=1;
		scanf("%d",&n);
		for(int i=0;i<2*n;i++) fa[i]=i;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
			p[2*i]=e[i].a;
			p[2*i+1]=e[i].b;
		}
		dis();
		for(int i=0;i<n;i++)
			if(e[i].c) Union(e[i].a,e[i].b);
		for(int i=0;i<n;i++)
			if(e[i].c==0&&find(e[i].a)==find(e[i].b))
			{
				flag=0;
				break;
			} 
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
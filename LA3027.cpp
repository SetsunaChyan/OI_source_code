#include <cstdio>

int par[20001],dis[20001],n;
char s[5];

inline int abs(int x)
{
	return x>0?x:-x;
}

int find(int x,int &u)
{
	if(par[x]==x) 
	{
		u=0;
		return x;
	}
	par[x]=find(par[x],u);
	u+=dis[x];
	dis[x]=u;
	return par[x];
}

inline void Union(int x,int y)
{
	dis[y]=abs(x-y)%1000;
	par[y]=x;
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) 
		{
			par[i]=i;
			dis[i]=0;
		}
		while(scanf("%s",s),s[0]!='O')
		{
			int x,y;
			if(s[0]=='E') 
			{
				y=0;
				scanf("%d",&x);
				find(x,y);
				printf("%d\n",y);
			}
			else 
			{
				scanf("%d%d",&x,&y);
				Union(y,x);
			}
		}
	}
	return 0;
}
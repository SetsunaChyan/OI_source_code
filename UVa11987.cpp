#include <cstdio>

typedef long long ll;
const int MAXN=1e5+50;
int n,m,fa[MAXN],cnt[MAXN];
struct root
{
	int son,par;
	ll sum;
}rt[MAXN];

int find(int x)
{
	if(x==rt[x].par) return x;
	if(rt[x].par!=rt[rt[x].par].par)
	{
		rt[rt[x].par].sum+=rt[x].sum;
		rt[rt[x].par].son+=rt[x].son;
	}
	return rt[x].par=find(rt[x].par);
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			rt[i].par=i;
			rt[i].son=1;
			rt[i].sum=i;
		}
		for(int i=0;i<m;i++)
		{
			int opt,x,y,a,b;
			scanf("%d%d",&opt,&x);
			a=find(rt[fa[x]].par);
			if(opt==3)
			{
				printf("%d %lld\n",rt[a].son,rt[a].sum);
			}
			else
			{
				scanf("%d",&y);
				b=find(rt[fa[y]].par);
				if(a==b) continue;
				if(opt==1)
				{
					rt[a].par=b;
					rt[b].son+=rt[a].son;
					rt[b].sum+=rt[a].sum;
				}
				else if(opt==2)
				{
					rt[a].son--;
					rt[a].sum-=x;
					rt[b].sum+=x;
					rt[b].son++;
					fa[x]=b;
				}
			}
		}
	}
	return 0;
}


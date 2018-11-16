#include <cstdio>
#include <memory.h>
#include <cstring>

const int MAXN=2e4+500;
int n,qq,par[MAXN],val[MAXN],a[300],flag;
char s[300];

int find(int x)
{
	if(x==par[x]) return x;
	int fa=find(par[x]);
	val[x]^=val[par[x]];
	par[x]=fa;
	return fa;
}

void Union(int x,int y,int v)
{
	int a=find(x),b=find(y);
	if(a==b)
	{
		if((val[x]^val[y])!=v)
		{
			flag=0;
			return;
		}
	}
	if(a==n)
	{
		int t=a;
		a=b;
		b=t;
	}
	par[a]=b;
	val[a]=(val[x]^val[y]^v);
}

int main()
{
	//freopen("data.out","w",stdout);
	int t=0;
	while(scanf("%d%d",&n,&qq),n)
	{
		t++;
		printf("Case %d:\n",t);
		memset(val,0,sizeof(val));
		for(int i=0;i<=n;i++) par[i]=i;
		flag=1;
		int cnt=0;
		while(qq--)
		{
			char opt;
			int p,q,v,k;
			scanf(" %c",&opt);
			if(opt=='I')
			{
				scanf("%[^\n]",s);
				cnt++;
				k=sscanf(s,"%d%d%d",&p,&q,&v);
				if(!flag) continue;
				if(k==2) Union(p,n,q); else Union(p,q,v);
				if(!flag) printf("The first %d facts are conflicting.\n",cnt);
			}
			else
			{
				scanf("%d",&k);
				int sum=0,flag1=1;
				for(int i=0;i<k;i++)
					scanf("%d",&a[i]);
				if(!flag) continue;
				for(int i=0;i<k;i++)
				{
					int g,m;
					if(a[i]!=-1)
					{
						g=0,m=find(a[i]);
						for(int j=i;j<k;j++)
							if(find(a[j])==m)
							{
								sum^=val[a[j]];
								a[j]=-1;
								g++;
							}
					}
					if((g&1)&&m!=n) flag1=0;
				}
				if(!flag1) printf("I don't know.\n"); else printf("%d\n",sum);
			}
		}
		printf("\n");
	}
	return 0;
}

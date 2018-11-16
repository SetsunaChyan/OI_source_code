#include <cstdio>
#include <memory.h>

const int MAXN=2e5+50;
int BIT[MAXN*2],mp[MAXN],n,q,head;

inline int lowbit(int x)
{
	return x&-x;
}

void add(int x,int y)
{
	for(;x<=MAXN*2;x+=lowbit(x)) BIT[x]+=y;
}

int sum(int x)
{
	int ret=0;
	for(;x>0;x-=lowbit(x)) ret+=BIT[x];
	return ret;
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--)
	{
		memset(BIT,0,sizeof(BIT));
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
		{
			add(MAXN*2-n+i-1,1);
			mp[i]=MAXN*2-n+i-1;
		}
		head=MAXN*2-n-1;
		while(q--)
		{
			int x;
			scanf("%d",&x);
			if(!q) printf("%d",sum(mp[x]-1)); else printf("%d ",sum(mp[x]-1));
			add(mp[x],-1);
			mp[x]=head--;
			add(mp[x],1);
		} 
		if(_!=0) printf("\n");
	}
	return 0;
}
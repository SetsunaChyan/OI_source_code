#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

const int MAXN=50;
int n,in[MAXN],post[MAXN],head,tail,vis[MAXN],mp[MAXN];
struct node
{
	int lev,pos,loc;
}tre[MAXN];

inline int find(int x)
{
	int i;
	for(i=0;i<n;i++)
		if(in[i]==x) break;
	return i;
}

void mpp()
{
	for(int i=0;i<n;i++)
		mp[i]=find(post[i]);
}

inline void add(int lev,int pos,int loc)
{
	tre[++tail].lev=lev;
	tre[tail].pos=pos;
	tre[tail].loc=loc;
}

inline bool cmp(node a,node b)
{
	if(a.lev!=b.lev) return a.lev<b.lev;
	if(a.lev&1) return a.pos>b.pos;
	return a.pos<b.pos;
}

int main()
{
	memset(tre,0,sizeof(tre));
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<n;i++) scanf("%d",&post[i]);
	mpp();
	tre[0].lev=1;tre[0].pos=mp[n-1];tre[0].loc=n-1;
	vis[n-1]=1;
	head=0;tail=0;
	do
	{
		int l=0,r=0;
		for(int i=tre[head].loc-1;i>=0;i--)
		{
			if(vis[i]) break;
			int temp=mp[i];
			if(temp!=n)
			{
				if(!l&&temp<tre[head].pos)
				{
					l=1;
					vis[i]=1;
					add(tre[head].lev+1,temp,i);
				} 
				else if(!r&&temp>tre[head].pos)
				{
					r=1;
					vis[i]=1;
					add(tre[head].lev+1,temp,i);
				}
			}
		}
		head++;
	}while(head<=tail);
	sort(tre,tre+n,cmp);
	printf("%d",in[tre[0].pos]);
	for(int i=1;i<n;i++)
		printf(" %d",in[tre[i].pos]);
	return 0;
}
#include <cstdio>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN=1e5+50;
struct node
{
	int par,pre,low,val;
}s[MAXN];
struct point
{
	int y,pos;
}p[MAXN],e[MAXN];
int BIT1[MAXN],BIT2[MAXN],n,q,g,hashtable[MAXN],cnt;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int find(int x)
{
	if(s[x].par==x) return x;
	return s[x].par=find(s[x].par);
}

inline void Union(int x,int y)
{
	s[x].par=y;
	s[y].val+=s[x].val;
	s[y].low=min(s[y].low,s[x].low);
	s[y].pre=max(s[y].pre,s[x].pre);
}

inline int lowbit(int x)
{
	return x&-x;
}

void add(int BIT[],int x,int y)
{
	for(;x<=cnt;x+=lowbit(x)) BIT[x]+=y;
}

int sum(int BIT[],int x)
{
	int ret=0;
	for(;x>0;x-=lowbit(x)) ret+=BIT[x];
	return ret;
}

inline bool cmp(point a,point b)
{
	return a.y<b.y;
}

void dis()
{
	sort(p+1,p+n+1,cmp);
	cnt=1;
	hashtable[1]=p[1].y;
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&p[i].y!=p[i-1].y) {cnt++;hashtable[cnt]=p[i].y;}
		e[p[i].pos].y=cnt;
		s[p[i].pos].low=s[p[i].pos].pre=cnt;
	}
}

inline int getrank(int key)
{
	int left=1,right=cnt;
	while(left<=right) 
	{
        int mid=(left+right)>>1;
        if(hashtable[mid]>key) 
            right=mid-1;
        else
            left=mid+1;
    }
    return right;
}

int main()
{
	int _;
	scanf("%d",&_);
	BIT1[0]=BIT2[0]=0;
	while(_--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%*d%d",&p[i].y);
			p[i].pos=i;
			s[i].par=i;
			s[i].val=1;
			BIT1[i]=BIT2[i]=0;
		}
		dis();
		scanf("%d",&q);
		while(q--)
		{
			char opt[10];
			int a,b;
			float c;
			scanf(" %s",opt);
			if(opt[0]=='r')
			{
				scanf("%d%d",&a,&b);
				a++;b++;
				int fa=find(a),fb=find(b);
				if(fa!=fb)
				{
					add(BIT1,s[fa].low,-1);
					add(BIT1,s[fa].pre,1);
					add(BIT1,s[fb].low,-1);
					add(BIT1,s[fb].pre,1);
					add(BIT2,s[fa].low,-s[fa].val);
					add(BIT2,s[fa].pre,s[fa].val);
					add(BIT2,s[fb].low,-s[fb].val);
					add(BIT2,s[fb].pre,s[fb].val);
					//QAQ
					Union(fa,fb);
					add(BIT2,s[fb].low,s[fb].val);
					add(BIT2,s[fb].pre,-s[fb].val);
					add(BIT1,s[fb].low,1);
					add(BIT1,s[fb].pre,-1);
				}
			}
			else
			{
				scanf("%f",&c);
				int g=getrank(floor(c));
				printf("%d %d\n",sum(BIT1,g),sum(BIT2,g));
			}	
		}
	}
	return 0;
}
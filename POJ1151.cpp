#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXN=110;
struct node
{
	double x,y1,y2;
	int op;
}e[MAXN*2];
double p[MAXN*2],b[MAXN*2],len[MAXN<<3],sum;
int n,cnt,ct[MAXN<<3];

inline bool cmp(node a,node b)
{
	return a.x<b.x;
}

inline int find_pos(double x)
{
	return lower_bound(b+1,b+cnt+1,x)-b;
}

void dis()
{
	cnt=1;
	sort(e,e+2*n,cmp);
	sort(p,p+2*n);
	for(int i=0;i<2*n;i++)
	{
		if(i&&p[i]!=p[i-1]) cnt++;
		b[cnt]=p[i];
	}
}

inline void pushup(int rt,int l,int r)
{
	if(!ct[rt])
		if(l!=r) len[rt]=len[rt<<1]+len[rt<<1|1]; else len[rt]=0;
	else
		len[rt]=b[r+1]-b[l];
}

void update(int L,int R,int x,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		ct[rt]+=x;
		pushup(rt,l,r);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,x,l,mid,rt<<1);
	if(R>mid) update(L,R,x,mid+1,r,rt<<1|1);
	pushup(rt,l,r);
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data1.out","w",stdout);
	int _=0;
	while(scanf("%d",&n)&&n)
	{
		_++;sum=0;
		for(int i=0;i<n;i++)
		{
			double x1,x2,yz1,yz2;
			scanf("%lf%lf%lf%lf",&x1,&yz1,&x2,&yz2);
			e[2*i].x=x1;
			e[2*i+1].x=x2;
			e[2*i].y1=e[2*i+1].y1=yz1;
			e[2*i].y2=e[2*i+1].y2=yz2;
			e[2*i].op=1;
			e[2*i+1].op=-1;
			p[2*i]=yz1;
			p[2*i+1]=yz2;
		}
		dis();
		memset(len,0,sizeof(len));
		memset(ct,0,sizeof(ct));
		for(int i=0;i<2*n;i++)
		{
			if(i) sum+=(e[i].x-e[i-1].x)*len[1];
			update(find_pos(e[i].y1),find_pos(e[i].y2)-1,e[i].op,1,cnt,1);
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",_,sum);
	}
	return 0;
}

/*
8
1 1 2 2
3 3 6 5
2 1 7 3
4 1 4 8
7 6 8 7
6 5 12 7
3 6.7 8 8
9 9 15.3 10
*/
#include <cstdio>
#include <memory.h>

struct pair{int first,second;};
int n,m,a[1000][1000],bit[1000*1000];

inline int lowbit(int x){return x&-x;}
inline int abs(int x){return x>0?x:-x;}
void add(int x,int y){for(;x<=n*m;x+=lowbit(x)) bit[x]+=y;}

int sum(int x)
{
	int ret=0;
	for(;x>0;x-=lowbit(x)) ret+=bit[x];
	return ret;
}

pair get()
{
	pair ret={0,0};
	memset(bit,0,sizeof(bit));
	int reta=0,retb,x;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i=n-1;i>=0;i--)
		for(int j=m-1;j>=0;j--)
			if(a[i][j]!=0)
			{
				add(a[i][j],1);
				ret.first+=sum(a[i][j]-1);
			}
			else
				ret.second=n-1-i;
	return ret;
}

int main()
{
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		int t;
		pair a=get();
		if((m&1)==0) t=a.second; else t=0;
		//printf("ddd %d %d\n",a.first,t);
		if((a.first+t)&1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

/*
4 3
1 	6 	2
4 	0 	3
7 	5 	9
10 	8 	11
3 2
1 2 
3 4 
5 0
3 2
1 2
3 0
5 4
*/
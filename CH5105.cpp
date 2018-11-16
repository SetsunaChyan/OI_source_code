#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long ll;
struct node
{
	int g,pos;
}e[31];
struct path
{
	int x,y;
}p[31][5001];
int n,m;
ll f[31][5001],pre[31];
inline bool cmp1(node a,node b){return a.pos<b.pos;}
inline bool cmp2(node a,node b){return a.g>b.g;}

void print(int lx,int ly)
{
	if(lx==0&&ly==0) return;
	int temp=ly;
	while(p[lx][ly].x==lx)
	{
		for(int i=1;i<=lx;i++)
			e[i].g++;
		lx=p[lx][ly].x;
		ly=p[lx][ly].y;
	}
	print(p[lx][ly].x,p[lx][ly].y);
}

int main()
{
	pre[0]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&e[i].g);
		e[i].pos=i;
	}
	memset(f,0x3f,sizeof(f));
	sort(e+1,e+n+1,cmp2);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+e[i].g;
	f[0][0]=0;
	p[0][0].x=0;
	p[0][0].y=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=m;j++)
		{
			if(f[i][j-i]<f[i][j])
			{
				f[i][j]=f[i][j-i];
				p[i][j].x=i;
				p[i][j].y=j-i;
			}
			for(int k=0;k<i;k++)
			{
				ll temp=k*(pre[i]-pre[k]);
				if(f[k][j-i+k]+temp<f[i][j])
				{
					f[i][j]=f[k][j-i+k]+temp;
					p[i][j].x=k;
					p[i][j].y=j-i+k;
				}
			}
		}
	printf("%lld\n",f[n][m]);
	for(int i=1;i<=n;i++) e[i].g=1;
	print(n,m);
	sort(e+1,e+n+1,cmp1);
	for(int i=1;i<=n;i++)
		printf("%d ",e[i].g);
	return 0;
}
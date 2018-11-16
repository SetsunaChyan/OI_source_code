#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int moved[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int vis[500][500],sig[500][500],h,w,d,mp[500][500],ans;

struct node
{
	int x,y,val;
}e[500*500],q[500*500];

inline bool cmp(node a,node b)
{
	return a.val>b.val;
}

void bfs(int num)
{
	int head=0,end=0,lim=e[num].val-d,maxn=e[num].val;
	q[0].x=e[num].x;
	q[0].y=e[num].y;
	vis[q[0].x][q[0].y]=1;
	do
	{
		for(int i=0;i<4;i++)
		{
			int nx=q[head].x+moved[i][0],ny=q[head].y+moved[i][1];
			if(nx>=0&&nx<h&&ny>=0&&ny<w&&vis[nx][ny])
				if(maxn<sig[nx][ny]) maxn=sig[nx][ny];
			if(nx>=0&&nx<h&&ny>=0&&ny<w&&!vis[nx][ny]&&mp[nx][ny]>lim)
			{
				end++;
				vis[nx][ny]=1;
				if(maxn<mp[nx][ny]) maxn=mp[nx][ny];
				q[end].x=nx;
				q[end].y=ny;
			}
		}
		head++;
	}while(head<=end);
	for(int i=0;i<=end;i++)
		sig[q[i].x][q[i].y]=maxn;
	if(maxn==e[num].val) ans++;
}


int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		memset(vis,0,sizeof(vis));
		memset(sig,0,sizeof(sig));
		int cnt=0;
		ans=0;
		scanf("%d%d%d",&h,&w,&d);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				scanf("%d",&e[cnt].val);
				mp[i][j]=e[cnt].val;
				e[cnt].x=i;
				e[cnt].y=j;
				cnt++;
			}
		sort(e,e+h*w,cmp);
		for(int i=0;i<h*w;i++) bfs(i);
		printf("%d\n",ans);
	}
	return 0;
}
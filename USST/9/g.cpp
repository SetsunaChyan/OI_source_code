#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int mp[5001][5001],r,c,n;
struct node
{
	int x,y;
}p[5000];

inline bool cmp(node a,node b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}

int main()
{
	int ans=0;
	memset(mp,0,sizeof(mp));
	scanf("%d%d%d",&r,&c,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		mp[p[i].x][p[i].y]=1;
	}
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int temp=0,dx=p[j].x-p[i].x,dy=p[j].y-p[i].y,nx=p[i].x-dx,ny=p[i].y-dy;
			if(nx<=r&&ny<=c&&nx>0&&ny>0) continue;
			for(nx+=dx,ny+=dy;nx<=r&&ny<=c&&nx>0&&ny>0;nx+=dx,ny+=dy)
				if(mp[nx][ny]) temp++; else {temp=0;break;}
			if(temp>ans) ans=temp;
		}
	}
	if(ans>=3)
		printf("%d",ans);
	else
		printf("0");
	return 0;
}
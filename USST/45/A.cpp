#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[1000][1000],x,y,xm=0x3f3f3f3f,ym=0x3f3f3f3f,sm=0x3f3f3f3f;
ll sum=0;

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==-1)
			{
				x=i;
				y=j;
			}
			else 
				sum+=a[i][j];
		}
	for(int i=0;i<n;i++)
		if(i!=y) xm=min(xm,a[x][i]);
	for(int i=0;i<n;i++)
		if(i!=x) ym=min(ym,a[i][y]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=x&&j!=y) sm=min(sm,a[i][j]);
	sum+=xm+ym-sm;
	printf("%d %d",xm+ym-sm,sum/n);
	return 0;
}
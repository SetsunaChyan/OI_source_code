#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,L,R,LOW,HIGH,lx,ly,x,y,sx,sy;
ll sum;

int main()
{
	freopen("intel.in","r",stdin);
	freopen("intel.out","w",stdout);
	LOW=L=1e7;
	R=HIGH=-1e7;
	scanf("%d",&n);
	scanf("%d%d",&lx,&ly);
	sx=lx,sy=ly;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		L=min(L,x);
		R=max(R,x);
		LOW=min(LOW,y);
		HIGH=max(HIGH,y);
		sum+=abs(x-lx)+abs(y-ly);
		lx=x,ly=y;
	}
	sum+=abs(sx-lx)+abs(sy-ly);
	sum-=2*(R-L)+2*(HIGH-LOW);
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

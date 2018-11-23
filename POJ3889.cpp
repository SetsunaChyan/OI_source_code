#include <cstdio>
#include <cmath>

int n,a,b;

void cal(int &x,int &y,int t,int num)
{
	if(t==0){x=1;y=1;return;}
	int d=(num-1)/(1<<2*t-2),nnum=(num-1)%(1<<2*t-2)+1,tx,ty;
	cal(x,y,t-1,nnum);
	if(d==0){tx=y;ty=x;}
	else if(d==1){tx=(1<<t-1)+x;ty=y;}
	else if(d==2){tx=(1<<t-1)+x;ty=(1<<t-1)+y;}
	else {tx=(1<<t-1)-y+1;ty=(1<<t)-x+1;}
	x=tx;
	y=ty;
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d",&n,&a,&b);
		cal(x1,y1,n,a);
		cal(x2,y2,n,b);
		printf("%.0lf\n",10.0*sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))));
	}
	return 0;
}
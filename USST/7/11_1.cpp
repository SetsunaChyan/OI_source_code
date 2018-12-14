#include <cstdio>
#include <algorithm>
#include <cmath>

const double eps=1e-3;
const char mp[4]={'+','-','*','/'};
int flag=0,a[4],opt[4];

inline double f(double val1,double val2,int x)
{
	if(x==0) return val1+val2;
	else if(x==1) return val1-val2;
	else if(x==2) return val1*val2;
	else return val1/val2;
}

void c1(int dep,double val)
{
	if(dep==3)
	{
		if(fabs(val-24.0)<eps) flag=1;
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(flag) return;
		opt[dep]=i;
		c1(dep+1,f(val,a[dep+1],i));
	}
}

void c2(int dep,double val1,double val2)
{
	if(dep==2)
	{
		for(int i=0;i<4;i++)
		{
			opt[dep]=i;
			if(fabs(f(val1,val2,i)-24.0)<eps) {flag=2;return;}
		}
		return;
	}
	std::swap(val1,val2);
	for(int i=0;i<4;i++)
	{
		if(flag) return;
		opt[dep]=i;
		c2(dep+1,val1,f(a[2*dep],a[2*dep+1],i));
	}
}

void c3()
{
	for(int i=0;i<4;i++)
	{
		opt[0]=i;
		for(int j=0;j<4;j++)
		{
			opt[1]=j;
			for(int k=0;k<4;k++)
			{
				opt[2]=k;
				double t1=f(a[2],a[3],k),t2=f(a[1],t1,j);
				if(fabs(f(a[0],t2,i)-24.0)<eps) {flag=3;return;}
			}
		}
	}
}

int main()
{
	for(int i=0;i<4;i++) scanf("%d",&a[i]);
	do
	{
		c1(0,a[0]);
		if(flag) break;
		c2(0,0,0);
		if(flag) break;
		c3();
		if(flag) break;
	}while(std::next_permutation(a,a+4));
	if(!flag)
		printf("-1");
	else if(flag==1)
		printf("((%d%c%d)%c%d)%c%d",a[0],mp[opt[0]],a[1],mp[opt[1]],a[2],mp[opt[2]],a[3]);
	else if(flag==2)
		printf("(%d%c%d)%c(%d%c%d)",a[0],mp[opt[0]],a[1],mp[opt[2]],a[2],mp[opt[1]],a[3]);
	else 
		printf("%d%c(%d%c(%d%c%d))",a[0],mp[opt[0]],a[1],mp[opt[1]],a[2],mp[opt[2]],a[3]);
	return 0;
}
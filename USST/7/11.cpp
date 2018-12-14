#include <cstdio>
#include <algorithm>
#include <cmath>

const double eps=1e-3;
const char mp[4]={'+','-','*','/'};
int flag=0,a[4],opt[4];

inline int f(int val1,int val2,int x)
{
	if(x==0) return val1+val2;
	else if(x==1) return val1-val2;
	else if(x==2) return val1*val2;
	else if(val1%val2==0) return val1/val2;
	else return -0x003f3f3f;
}

inline bool p(int a,int b)
{
	if((a==0||a==1)&&(b==2||b==3)) return true;
	return false;
}

void dfs1(int dep,int val)
{
	if(dep==3)
	{
		if(val==24) flag=1;
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(flag) return;
		opt[dep]=i;
		dfs1(dep+1,f(val,a[dep+1],i));
	}
}

void dfs2(int dep,double val1,double val2)
{
	if(dep==2)
	{
		for(int i=0;i<4;i++)
		{
			opt[dep]=i;
			if(f(val1,val2,i)==24) {flag=2;return;}
		}
		return;
	}
	std::swap(val1,val2);
	for(int i=0;i<4;i++)
	{
		if(flag) return;
		opt[dep]=i;
		dfs2(dep+1,val1,f(a[2*dep],a[2*dep+1],i));
	}
}

int main()
{
	for(int i=0;i<4;i++) scanf("%d",&a[i]);
	do
	{
		dfs1(0,a[0]);
		if(flag) break;
		dfs2(0,0,0);
		if(flag) break;
	}while(std::next_permutation(a,a+4));
	if(!flag)
		printf("-1");
	else if(flag==1)
	{
		if(p(opt[0],opt[1])) printf("(");
		if(p(opt[1],opt[2])) printf("(");
		printf("%d%c%d",a[0],mp[opt[0]],a[1]);
		if(p(opt[0],opt[1])) printf(")");
		printf("%c%d",mp[opt[1]],a[2]);
		if(p(opt[1],opt[2])) printf(")");
		printf("%c%d",mp[opt[2]],a[3]);
		//printf("((%d%c%d)%c%d)%c%d",a[0],mp[opt[0]],a[1],mp[opt[1]],a[2],mp[opt[2]],a[3]);
	}
	else 
	{
		if(p(opt[0],opt[2])) printf("(");
		printf("%d%c%d",a[0],mp[opt[0]],a[1]);
		if(p(opt[0],opt[2])) printf(")");
		printf("%c",mp[opt[2]]);
		if(p(opt[1],opt[2])) printf("(");
		printf("%d%c%d",a[2],mp[opt[1]],a[3]);
		if(p(opt[1],opt[2])) printf(")");
		//printf("(%d%c%d)%c(%d%c%d)",a[0],mp[opt[0]],a[1],mp[opt[2]],a[2],mp[opt[1]],a[3]);
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <cmath>

int len=0;
char s[2000];

double readd(int &cur)
{
	int flag=0;
	double ret=0,b=0,t=1;
	if(s[cur]=='-') {flag=1; cur++;}
	while(s[cur]>='0'&&s[cur]<='9')
	{
		ret=ret*10+(s[cur]-'0');
		cur++;
	}
	if(s[cur]!='.') {if(flag) ret*=-1; cur++; return ret;}
	cur++;
	while(s[cur]>='0'&&s[cur]<='9')
	{
		b=b*10+(s[cur]-'0');
		t*=10;
		cur++;
	}
	cur++;
	//printf("%lf\n",ret+b/t);
	return ret+b/t;
}

double cal(int &cur)
{
	double p,x,y,z;
	char opt=s[cur];
	if(opt=='('||opt==' ')
	{
		cur++;
		p=cal(cur);
		x=cal(cur);
		y=cal(cur);
		cur++;
		z=p*(x+y)+(1-p)*(x-y);
	}
	else
	{
		z=readd(cur);
	}
	return z;
}

int main()
{
	int cur=0;
	//freopen("e.txt","r",stdin);
	while(~scanf("%c",&s[len++]));
	printf("%.2lf",cal(cur));
	return 0;
}
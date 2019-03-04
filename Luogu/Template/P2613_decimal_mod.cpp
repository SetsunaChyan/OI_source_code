#include <cstdio>
#include <cstring>

const int MOD=19260817; 
int a,b;

int read()
{
	char s[10002];
	scanf("%s",s);
	int ret=s[0]-'0',len=strlen(s);
	for(int i=1;i<len;i++)
		ret=(ret*10+(s[i]-'0'))%MOD;
	return ret;
}

int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return b;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

int main()
{
	a=read();b=read();
	int x,y;
	exgcd(b,MOD,x,y);
	x=(x+MOD)%MOD;
	if(b==0)
		printf("Angry!\n");
	else
		printf("%lld\n",(long long)a*x%MOD);
	return 0;
}
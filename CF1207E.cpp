#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,x,y;

int main()
{
	printf("? %lld",(a=127)*128);
	for(int i=0;i<99;i++) printf(" %lld",a*128+i+1);
	printf("\n");
	fflush(stdout);
	cin>>x;
	printf("? %lld",a);
	for(int i=0;i<99;i++) printf(" %lld",(i+1)*128ll+a);
	printf("\n");
	fflush(stdout);
	cin>>y;
	x/=128;x&=a;x*=128;y&=a;
	x+=y;
	x=16383ll-x;
	printf("! %lld\n",x);
	fflush(stdout);
	return 0;
}

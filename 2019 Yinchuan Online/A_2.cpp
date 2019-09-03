#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
int n,p,q,m;
ui sa,sb,sc;
unordered_map<ui,int>h;
ui s[10000007];
int sz=0;
ui rng()
{
	sa^=sa<<16;
	sa^=sa>>5;
	sa^=sa<<1;
	ui t=sa;sa=sb;
	sb=sc;
	sc^=t^sa;
	return sc;
}
void push(ui x)
{
	h[x]++;
	s[++sz]=x;
}
void pop()
{
	if(sz)
	{
		if(!--h[s[sz]])
			h.erase(s[sz]);
		--sz;
	}
}
long long gen()
{
	h.clear();
	sz=0;
	long long ans=0;
	scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&sa,&sb,&sc);
	for(int i=1;i<=n;i++)
	{
		if(rng()%(p+q)<p)
			push(rng()%m+1);
		else
			pop();
		if(sz)
			ans^=i*h.rbegin()->first;
	}
	return ans;
}
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		printf("Case #%d: ",__);
		printf("%lld\n",gen());
	}
	return 0;
}

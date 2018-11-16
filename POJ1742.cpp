#include <cstdio>
#include <memory.h>

int f[100005],n,m,a[100],b[100],_=0;

void zopack(int w)
{
	for(int i=m;i>=w;i--)
		if(f[i-w]==_) f[i]=_;
}

void compack(int w)
{
	for(int i=w;i<=m;i++)
		if(f[i-w]==_) f[i]=_;
}

void multipack(int w,int c)
{
	if(c*w>=m)
	{
		compack(w);
		return;
	}
	int cnt=1;
	while(c>=cnt)
	{
		zopack(w*cnt);
		c-=cnt;
		cnt*=2;
	}
	if(c) zopack(w*c);
}

int main()
{
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		_++;
		int sum=0;
		f[0]=_;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) scanf("%d",&b[i]);
		for(int i=0;i<n;i++)
			multipack(a[i],b[i]);
		for(int i=1;i<=m;i++)
			if(f[i]==_) sum++;
		printf("%d\n",sum);
	}
	return 0;
}
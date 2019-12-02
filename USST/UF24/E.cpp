#include <cstdio>

int sum=0,m=0x3f3f3f3f,n,b=0;

inline int abs(int x){return x<0?-x:x;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<2*n-1;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<0) b++;
		m=min(m,abs(x));
		sum+=abs(x);
	}
	if(n%2||b%2==0)
		printf("%d",sum);
	else
		printf("%d",sum-2*m);
	return 0;
}

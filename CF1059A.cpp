#include <cstdio>

const int MAXN=1e5+50;
int t[MAXN],l[MAXN];

int main()
{
	int n,L,a,sum=0;
	scanf("%d%d%d",&n,&L,&a);
	t[0]=0;l[0]=0;
	t[n+1]=L;
	for(int i=1;i<=n+1;i++)
	{
		if(i!=n+1) scanf("%d%d",&t[i],&l[i]);
		sum+=(t[i]-(t[i-1]+l[i-1]))/a;
	}
	printf("%d\n",sum);
	return 0;
}
#include <cstdio>

typedef long long ll;
const int MAXN=1e6+50;
char a[MAXN],b[MAXN];
int c[MAXN];
ll n;

int main()
{
	ll ans=0,k=0;
	scanf("%lld",&n);
	scanf("%s%s",a,b);
	for(int i=0;i<n;i++)
		c[i]=(a[i]-'0')^(b[i]-'0');
	for(int i=0;i<n;i++)
		if(c[i]&&(!i||!c[i-1])) k++;
	if(k>2)
		printf("0");
	else if(k==0)
		printf("%lld",(1+n)*n/2);
	else if(k==2)
		printf("6");
	else if(k==1)
		printf("%lld",2*(n-1));
	return 0;
}
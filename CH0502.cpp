#include <cstdio>
#include <algorithm>

typedef long long ll;
const int MAXN=100005;
int n,m;
ll a[MAXN],b[MAXN],s[MAXN],sum,can=0,ans=0,temp;

inline ll abs(ll x){return x<0?-x:x;}

void test(ll s[],int n,int sig)
{
	sum=0;
	for(int i=0;i<n;i++)
	 	sum+=s[i];
	if(sum%n!=0) return;
	sum/=n,can+=sig;
	s[0]-=sum;
	for(int i=1;i<n;i++)
		s[i]+=s[i-1]-sum;
	std::sort(s,s+n);
	temp=s[n/2];
	for(int i=0;i<n;i++)
		ans+=abs(temp-s[i]);
}

int main()
{
	int t;
	scanf("%d%d%d",&n,&m,&t);
	while(t--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		a[x-1]++;//row
		b[y-1]++;
	}
	test(a,n,1);
	test(b,m,2);
	if(can==0)
	{
		printf("impossible");
		return 0;
	}
	if(can==1)
		printf("row");
	else if(can==2)
		printf("column");
	else
		printf("both");
	printf(" %lld",ans);
	return 0;
}
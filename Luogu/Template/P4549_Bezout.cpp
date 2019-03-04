#include <cstdio>

int n,a[20];

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=a[i]<0?-a[i]:a[i];
		if(i==1) 
			ans=gcd(a[i],a[i-1]);
		else if(i>1)
			ans=gcd(ans,a[i]);
	}
	printf("%d\n",ans);
	return 0;
}
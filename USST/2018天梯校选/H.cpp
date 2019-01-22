#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int tot=0,prime[20000];

bool is_prime(int x)
{
	int l=sqrt(x);
	for(int i=2;i<=l;i++)
		if(x%i==0) return false;
	return true;
}

inline int find(int x){return *lower_bound(prime,prime+tot,x);}

int main()
{
	int n;
	for(int i=2;i<20000;i++)
	{
		if(is_prime(i))
			prime[tot++]=i;
	}
	while(~scanf("%d",&n)&&n)
	{
		for(int i=tot-1;i>=0;i--)
		{
			if(n-prime[i]<prime[i]) continue;
			if(find(n-prime[i])==n-prime[i])
			{
				printf("%d %d\n",prime[i],n-prime[i]);
				break;
			}
		}
	}
	return 0;
}
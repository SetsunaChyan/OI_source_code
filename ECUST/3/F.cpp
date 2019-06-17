#include <bits/stdc++.h>
using namespace std;

int n,rk[400005];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		rk[x]=i;
	}
	if(n<=10000)
	{
		for(int i=1;i<n;i++)
			for(int k=1;k<=i;k++)
				for(int j=k+i;j<n-i;j+=i)
					if(rk[j-i]<rk[j]&&rk[j]<rk[j+i]||rk[j-i]>rk[j]&&rk[j]>rk[j+i])
					{
						printf("YES");
						return 0;
					}
		printf("NO");
		return 0;
	}
	for(int i=1;i<n;i++)
		for(int j=1+i;j<n-i;j+=i)
			if(rk[j-i]<rk[j]&&rk[j]<rk[j+i]||rk[j-i]>rk[j]&&rk[j]>rk[j+i])
			{
				printf("YES");
				return 0;
			}
	printf("NO");
	return 0;
}

#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

int ocp[300];

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		int n,cost=0;
		memset(ocp,0,sizeof(ocp));
		scanf("%d",&n);
		while(n--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a==b) continue;
			if(a>b) swap(a,b);
			a++,b++; 
			a/=2,b/=2;
			for(int i=a;i<=b;i++) ocp[i]++;
		}
		for(int i=0;i<=200;i++)
			cost=max(cost,ocp[i]);
		printf("%d\n",cost*10);
	}	
	return 0;
}

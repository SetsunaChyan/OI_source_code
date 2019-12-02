#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35;
const int inf=0x3f3f3f3f;

int n,sum=0;
pair<int,int> p[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].first);
		p[i].second=i;
		sum+=p[i].first;
	}
	sort(p+1,p+1+n);
	bool can=1;
	for(int i=1;i<=n;++i)
	{
		if(p[i].first>sum/2)
		{
			can=0;
			break;
		}
	}
	if(!can) puts("impossible");
	else
	{
		for(int i=n;i>=1;--i)
			printf("%d ",p[i].second);
	}
	return 0;
}

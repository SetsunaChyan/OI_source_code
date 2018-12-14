#include <cstdio>
#include <map>

using namespace std;

map<int,int> m;
inline int max(int a,int b){return a>b?a:b;}

int main()
{
	m.clear();
	int ans=0,n;
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		if(m.find(x)==m.end())
			m[x]=1;
		else
			m[x]++;
		ans=max(m[x],ans);
	}
	printf("%d",ans);
	return 0;
}
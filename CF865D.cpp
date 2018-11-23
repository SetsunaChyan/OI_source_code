#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int n;
long long ans = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if(!q.empty() && x > q.top())
		{
			ans += x - q.top();
			q.pop();
			q.push(x);
		}
		q.push(x);
	}
	printf("%I64d\n", ans);
	return 0;
}
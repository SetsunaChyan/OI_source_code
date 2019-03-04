#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int BIT[MAXN], n = 1, a[MAXN], dp[MAXN], maxseq;
struct node
{
	int val, pos;
} hash[MAXN];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline int lowbit(int x)
{
	return x & -x;
}

int maxn(int x)
{
	int ret = 0;
	for(; x >= 1; x -= lowbit(x)) ret = max(ret, BIT[x]);
	return ret;
}

void updata(int x, int y)
{
	for(; x <= n; x += lowbit(x)) BIT[x] = max(y, BIT[x]);
}

inline bool cmp(node a, node b)
{
	return a.val < b.val;
}

void discretization()
{
	int cnt = 1;
	sort(hash + 1, hash + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		if(i != 1 && hash[i].val != hash[i - 1].val) cnt++;
		a[hash[i].pos] = cnt;
	}
}

int main()
{
	while(~scanf("%d", &hash[n].val))
	{
		hash[n].pos = n;
		n++;
	}
	n--;
	discretization();

	memset(BIT, 0, sizeof(BIT));
	dp[n] = 1; maxseq = 0;
	updata(a[n], 1);
	for(int i = n - 1; i >= 1; i--)
	{
		dp[i] = maxn(a[i]) + 1;
		updata(a[i], dp[i]);
	}
	for(int i = 1; i <= n; i++)
		maxseq = max(maxseq, dp[i]);
	printf("%d ", maxseq);

	memset(BIT, 0, sizeof(BIT));
	dp[1] = 1; maxseq = 0;
	updata(a[1], 1);
	for(int i = 2; i <= n; i++)
	{
		dp[i] = maxn(a[i] - 1) + 1;
		updata(a[i], dp[i]);
	}
	for(int i = 1; i <= n; i++)
		maxseq = max(maxseq, dp[i]);
	printf("%d\n", maxseq);

	return 0;
}
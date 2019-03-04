#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXN = 100005;
int n, a[MAXN], BIT[MAXN], ub[MAXN][2], ans = 0;
struct node
{
	int val, pos;
} hash[MAXN];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline int min(int a, int b)
{
	return a < b ? a : b;
}

inline bool cmp(node a, node b)
{
	return a.val > b.val;
}

void discretization()
{
	sort(hash + 1, hash + n + 1, cmp);
	int cnt = 1;
	for(int i = 1; i <= n; i++)
		a[hash[i].pos] = cnt++;
}

inline int lowbit(int x)
{
	return x & -x;
}

void add(int x, int y)
{
	for(; x <= n; x += lowbit(x)) BIT[x] += y;
}

int sum(int x)
{
	int ret = 0;
	for(; x >= 1; x -= lowbit(x)) ret += BIT[x];
	return ret;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &hash[i].val);
		hash[i].pos = i;
	}
	discretization();
	memset(BIT, 0, sizeof(BIT));
	for(int i = 1; i <= n; i++)
	{
		add(a[i], 1);
		ub[i][0] = sum(a[i] - 1);
	}
	memset(BIT, 0, sizeof(BIT));
	for(int i = n; i >= 1; i--)
	{
		add(a[i], 1);
		ub[i][1] = sum(a[i] - 1);
		if(max(ub[i][1], ub[i][0]) > 2 * min(ub[i][0], ub[i][1])) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
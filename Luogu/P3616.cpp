#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXN = 200100;

int BIT[MAXN * 2], a[MAXN], n, m, top;

struct query
{
	int opt, v1, v2;
} q[MAXN];

struct node
{
	int val, pos, q;
} hash[MAXN * 2];

inline bool cmp(node a, node b)
{
	return a.val < b.val;
}

void discretization()
{
	sort(hash + 1, hash + n + 2 + m + 1, cmp);
	int cnt = 1;
	for(int i = 1; i <= n + m + 2; ++i)
	{
		if(i != 1 && hash[i].val != hash[i - 1].val) cnt++;
		if(hash[i].q == 1)
			q[hash[i].pos].v2 = cnt;
		else
			a[hash[i].pos] = cnt;
	}
	top = cnt;
}

inline int max(int x, int y)
{
	return x > y ? x : y;
}

inline int min(int x, int y)
{
	return x < y ? x : y;
}

inline int lowbit(int x)
{
	return x & -x;
}

void add(int x, int y)
{
	for(; x <= top; x += lowbit(x)) BIT[x] += y;
}

int sum(int x)
{
	int ret = 0;
	for(; x >= 1; x -= lowbit(x)) ret += BIT[x];
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(BIT, 0, sizeof(BIT));
	hash[1].val = 0; hash[1].pos = 1; hash[1].q = 0;
	hash[n + 2].val = 0; hash[n + 2].pos = n + 2; hash[n + 2].q = 0;
	for (int i = 2; i <= n + 1; ++i)
	{
		scanf("%d", &hash[i].val);
		hash[i].pos = i;
		hash[i].q = 0;
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &q[i].opt);
		if(q[i].opt == 1) scanf("%d", &q[i].v2); else scanf("%d%d", &q[i].v1, &q[i].v2);
		q[i].v1++;
		hash[n + 2 + i].val = q[i].v2;
		hash[n + 2 + i].q = 1;
		hash[n + 2 + i].pos = i;
	}
	discretization();
	for(int i = 2; i <= n + 2; ++i)
	{
		add(max(a[i - 1], a[i]), 1);
		add(min(a[i - 1], a[i]), -1);
	}
	for(int i = 1; i <= m; ++i)
	{
		if(q[i].opt == 1)
			printf("%d\n", (sum(top) - sum(q[i].v2 - 1)) >> 1);
		else
		{
			int j = q[i].v1;
			add(max(a[j - 1], a[j]), -1);
			add(max(a[j], a[j + 1]), -1);
			add(min(a[j - 1], a[j]), 1);
			add(min(a[j], a[j + 1]), 1);
			a[j] = q[i].v2;
			add(max(a[j - 1], a[j]), 1);
			add(max(a[j], a[j + 1]), 1);
			add(min(a[j - 1], a[j]), -1);
			add(min(a[j], a[j + 1]), -1);
		}
	}

	return 0;
}
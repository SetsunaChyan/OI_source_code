#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

int BIT[MAXN], a[MAXN], n;
struct node
{
	int v, pos;
} hash[MAXN];

long long ans = 0;

inline int lowbit(int x)
{
	return x & -x;
}

void add(int x, int y)
{
	for(; x <= n; x += lowbit(x)) BIT[x] += y;
}

long long sum(int x)
{
	long long ret = 0;
	for(; x >= 1; x -= lowbit(x)) ret += BIT[x];
	return ret;
}

bool cmp(node a, node b)
{
	return a.v > b.v;
}

int main()
{
	scanf("%d", &n);
	BIT[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &hash[i].v);
		hash[i].pos = i;
		BIT[i] = 0;
	}
	sort(hash + 1, hash + n + 1, cmp);
	int cnt = 1;
	for(int i = 1; i <= n; i++)
	{
		if(i != 1 && hash[i].v != hash[i - 1].v) cnt++;
		a[hash[i].pos] = cnt;
	}
	for(int i = 1; i <= n; i++)
	{
		add(a[i], 1);
		ans += sum(a[i] - 1);
	}
	printf("%lld\n", ans);
	return 0;
}
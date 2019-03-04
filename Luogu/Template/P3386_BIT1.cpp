#include <cstdio>

const int MAXN = 500005;

int n, m, a[MAXN];
long long BIT[MAXN];

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

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	while(m--)
	{
		int opt, x, y;
		scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1)
			add(x, y);
		else
			printf("%lld\n", sum(y) - sum(x - 1));
	}
	return 0;
}
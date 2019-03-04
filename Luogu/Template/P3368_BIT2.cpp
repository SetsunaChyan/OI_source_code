#include <cstdio>

const int MAXN = 500005;

int n, m, a[MAXN], BIT[MAXN];

inline int lowbit(int x)
{
	return x & -x;
}

void add(int x, int y)
{
	for(; x <= n; x += lowbit(x)) BIT[x] += y;
}

void add(int l, int r, int y)
{
	for(; l <= n; l += lowbit(l)) BIT[l] += y;
	for(r++; r <= n; r += lowbit(r)) BIT[r] -= y;
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
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		add(i, a[i] - a[i - 1]);
	}
	while(m--)
	{
		int opt, x, y, k;
		scanf("%d", &opt);
		if(opt == 1)
		{
			scanf("%d%d%d", &x, &y, &k);
			add(x, y, k);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", sum(x));
		}
	}
	return 0;
}
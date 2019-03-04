#include <cstdio>

const int MAXN = 100002;

int del[MAXN], n, m;

struct node
{
	int ls, rs, val;
} tree[MAXN];

void add(int x, int y, int p)
{
	tree[x].val = 1;
	if(p == 0)
	{
		tree[x].rs = y;
		tree[x].ls = tree[y].ls;
		tree[tree[y].ls].rs = x;
		tree[y].ls = x;
	}
	else
	{
		tree[x].ls = y;
		tree[x].rs = tree[y].rs;
		tree[tree[y].rs].ls = x;
		tree[y].rs = x;
	}
}

int main()
{
	scanf("%d", &n);
	tree[1].ls = 0; tree[1].rs = n + 1; tree[1].val = 1;
	tree[n + 1].ls = 1; tree[n + 1].val = 0;
	tree[0].rs = 1; tree[0].val = 0;
	for(int i = 2; i <= n; i++)
	{
		int x, p;
		scanf("%d%d", &x, &p);
		add(i, x, p);
	}
	scanf("%d", &m);
	while(m--)
	{
		int x;
		scanf("%d", &x);
		tree[x].val = 0;
	}
	for(int cur = 0; cur != n + 1; cur = tree[cur].rs)
		if(tree[cur].val) printf("%d ", cur);

	return 0;
}
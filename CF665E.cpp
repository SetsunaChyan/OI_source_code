#include <cstdio>
#include <memory.h>

const int MAXN = 1 << 24;

struct node
{
	int val, next[2];
} trie[MAXN];
int n, h = 1, k;

void insert(int x)
{
	int rt = 0;
	for(int i = 30; i >= 0; i--)
	{
		int c = (x >> i) & 1;
		if(!trie[rt].next[c]) trie[rt].next[c] = h++;
		rt = trie[rt].next[c];
		trie[rt].val++;
	}
}

long long find(int x)
{
	int rt = 0;
	long long ret = 0;
	for(int i = 30; i >= 0; i--)
	{
		int c = ((x >> i) & 1) ^ 1, d = (k >> i) & 1;
		if(rt == 0 && i != 30) break;
		if(d == 0)
		{
			ret += trie[trie[rt].next[c]].val;
			rt = trie[rt].next[c ^ 1];
		}
		else
			rt = trie[rt].next[c];
	}
	ret += trie[rt].val;
	return ret;
}

int main()
{
	int prefix = 0;
	long long ans = 0;
	memset(trie, 0, sizeof(trie));
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		int x;
		insert(prefix);
		scanf("%d", &x);
		prefix ^= x;
		ans += find(prefix);
	}
	printf("%I64d\n", ans);
	return 0;
}
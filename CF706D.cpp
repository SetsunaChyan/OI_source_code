#include <cstdio>
#include <memory.h>

const int I = 1 << 31;

struct node
{
	int val, num, next[2];
} trie[32 * 200000];

int h = 1, n;

int add()
{
	memset(&trie[h], 0, sizeof(node));
	return h++;
}

void insert(int x)
{
	int rt = 0, temp = x;
	for(int i = 0; i < 32; i++)
	{
		int c = (x & I) >> 31;
		c = -c;
		x = x << 1;
		if(!trie[rt].next[c])
			trie[rt].next[c] = add();
		rt = trie[rt].next[c];
		trie[rt].val++;
	}
	trie[rt].num = temp;
}

void del(int x)
{
	int rt = 0;
	for(int i = 0; i < 32; i++)
	{
		int c = (x & I) >> 31;
		c = -c;
		x <<= 1;
		rt = trie[rt].next[c];
		trie[rt].val--;
	}
}

int find(int x)
{
	int rt = 0;
	for(int i = 0; i < 32; i++)
	{
		int c = (x & I) >> 31;
		c = -c;
		x <<= 1;
		if(trie[trie[rt].next[1 - c]].val)
			c = 1 - c;
		rt = trie[rt].next[c];
	}
	return trie[rt].num;
}

int main()
{
	memset(&trie[0], 0, sizeof(node));
	insert(0);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		char op;
		int opn;
		scanf(" %c%d", &op, &opn);
		if(op == '+')
			insert(opn);
		else if(op == '-')
			del(opn);
		else
			printf("%d\n", opn ^ find(opn));
	}
	return 0;
}
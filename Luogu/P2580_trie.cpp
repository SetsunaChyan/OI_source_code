#include <cstdio>
#include <memory>
#include <cstring>

struct node
{
	int val, next[26];
} trie[500100];

int h = 1, n;
char s[51];

int add()
{
	memset(&trie[h], 0, sizeof(node));
	return h++;
}

void insert(char *s)
{
	int rt = 0, len = strlen(s);
	for(int i = 0; i < len; i++)
	{
		int c = s[i] - 'a';
		if(!trie[rt].next[c])
			trie[rt].next[c] = add();
		rt = trie[rt].next[c];
	}
	trie[rt].val++;
}

void find(char *s)
{
	int rt = 0, len = strlen(s);
	for(int i = 0; i < len; i++)
	{
		int c = s[i] - 'a';
		if(!trie[rt].next[c])
		{
			printf("WRONG\n");
			return;
		}
		rt = trie[rt].next[c];
	}
	if(trie[rt].val == 1)
	{
		printf("OK\n");
		trie[rt].val++;
	}
	else if(trie[rt].val == 0)
		printf("WRONG\n");
	else
		printf("REPEAT\n");
}

int main()
{
	memset(&trie[0], 0, sizeof(node));
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", s);
		insert(s);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", s);
		find(s);
	}
}

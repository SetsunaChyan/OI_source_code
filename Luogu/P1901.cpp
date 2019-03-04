#include <cstdio>

const int MAXN = 1000000;

int n, stack[MAXN], h[MAXN], v[MAXN], ans[MAXN], e = 0, maxn = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		ans[i] = 0;
		scanf("%d%d", &h[i], &v[i]);
	}
	for(int i = 0; i < n; i++)
	{
		while(e != 0 && h[stack[e - 1]] <= h[i]) e--;
		stack[e++] = i;
		if(e != 1) ans[stack[e - 2]] += v[i];
	}
	e = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		while(e != 0 && h[stack[e - 1]] <= h[i]) e--;
		stack[e++] = i;
		if(e != 1) ans[stack[e - 2]] += v[i];
	}
	for(int i = 0; i < n; i++)
		if(maxn < ans[i]) maxn = ans[i];
	printf("%d\n", maxn);
	return 0;
}

/*
6
5 1
6 2
8 3
7 4
1 5
3 6
*/
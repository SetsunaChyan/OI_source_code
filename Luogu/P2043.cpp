#include <cstdio>

int p[10001], n;

int main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		int x = i;
		p[i] = 0;
		for(int j = 2; j * j <= x; j++)
			while(x % j == 0)
			{
				x /= j;
				p[j]++;
			}
		if(x > 1) p[x]++;
	}
	for(int i = 1; i <= n; i++)
		if(p[i] != 0) printf("%d %d\n", i, p[i]);
	return 0;
}
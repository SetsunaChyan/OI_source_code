#include <cstdio>

const int move[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int n, a[30][30], vis[30][30];

bool dfs(int x, int y, int m)
{
	if(m == 1) a[x][y] = 2;
	for(int i = 0; i < 4; i++)
	{
		int tx = x + move[i][0], ty = y + move[i][1];
		if(tx >= 0 && tx < n && ty >= 0 && ty < n && (!vis[tx][ty] || m == 1) && a[tx][ty] == 0)
		{
			if(tx == 0 || tx == n - 1 || ty == 0 || ty == n - 1) return false;
			vis[tx][ty]++;
			if(!dfs(tx, ty, m)) return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			vis[i][j] = 0;
			scanf("%d", &a[i][j]);
		}
	int k;
	for(int i = 1; i < n - 1; i++)
	{
		for(int j = 1; j < n - 1; j++)
		{
			if(!vis[i][j] && a[i][j] == 0)
			{
				k = dfs(i, j, 0);
				if(k)
				{
					dfs(i, j, 1);
					break;
				}
			}
		}
		if(k) break;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}

/*
6
0 1 1 1 0 0
1 1 0 1 1 1
1 0 0 0 0 1
1 1 1 1 0 1
1 0 0 0 0 1
1 1 1 1 1 1

*/
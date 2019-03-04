#include <cstdio>

int n;
const char m[8] = "yizhong";
const int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char a[100][101];
int o[100][100];

bool dfs(int d, int x, int y, int dep)
{
	int tx = x + dir[d][0], ty = y + dir[d][1];
	if(tx >= 0 && ty >= 0 && tx < n && ty < n && a[tx][ty] == m[dep])
	{
		if(dep == 6)
		{
			o[x][y] = 1;
			o[tx][ty] = 1;
			return true;
		}
		if(dfs(d, tx, ty, dep + 1))
		{
			o[x][y] = 1;
			return true;
		}
	}
	else
		return false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", a[i]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			o[i][j] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] == 'y')
				for(int k = 0; k < 8; k++)
					dfs(k, i, j, 1);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(o[i][j])
				printf("%c", a[i][j]);
			else
				printf("*");
		printf("\n");
	}
	return 0;
}
/*
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg
*/
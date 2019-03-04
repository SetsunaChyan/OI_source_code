#include <cstdio>
#include <cstring>

char s[20][255], head;
int n, maxn = 0, ans, vis[20];

inline int min(int a, int b)
{
	return a < b ? a : b;
}

int min_cover(int sa, int sb)
{
	int la = strlen(s[sa]);
	int lb = strlen(s[sb]);
	for(int i = 1; i < min(la, lb); i++)
	{
		int flag = 0;
		for(int j = la - i, k = 0; j < la; j++, k++)
		{
			if(s[sa][j] != s[sb][k])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0) return i;
	}
	return 0;
}

void dfs(int last)
{
	for(int i = 0; i < n; i++)
	{
		if(vis[i] == 2) continue;
		int cov = min_cover(last, i);
		if(cov == 0) continue;
		vis[i]++;
		ans += strlen(s[i]) - cov;
		if(ans > maxn) maxn = ans;
		dfs(i);
		vis[i]--;
		ans -= strlen(s[i]) - cov;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		vis[i] = 0;
	}
	scanf(" %c", &head);
	for(int i = 0; i < n; i++)
		if(s[i][0] == head)
		{
			ans = strlen(s[i]);
			vis[i]++;
			if(ans > maxn) maxn = ans;
			dfs(i);
			vis[i]--;
		}
	printf("%d\n", maxn);
	return 0;
}
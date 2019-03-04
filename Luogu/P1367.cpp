#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
struct node
{
	int p, d, dir;
} a[MAXN], atarashi[MAXN];
int pos[MAXN], n, t;

inline int cmp(node a, node b)
{
	return a.d < b.d;
}

int main()
{
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].d, &a[i].dir);
		a[i].p = i;
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i++)
	{
		a[i].d += a[i].dir * t;
		pos[i] = a[i].p;
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i++)
	{
		atarashi[pos[i]].d = a[i].d;
		if(i != 0 && a[i].d == a[i - 1].d || i != n - 1 && a[i].d == a[i + 1].d)
			atarashi[pos[i]].dir = 0;
		else
			atarashi[pos[i]].dir = a[i].dir;
	}
	for(int i = 0; i < n; i++)
		printf("%d %d\n", atarashi[i].d, atarashi[i].dir);
	return 0;
}
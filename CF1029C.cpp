#include <cstdio>
#include <algorithm>

using namespace std;

int n, ans, r1 = 1e9 + 1, r2 = 1e9 + 1, l1 = -1,l2 = -1;

inline void swap(int &a, int &b)
{
	int t = a; a = b; b = t;
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int flag = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int k = 0, l, r;
		scanf("%d%d", &l, &r);
		if(l2 < l) l2 = l;
		if(l1 < l2)
		{
			swap(l1, l2);
			k++;
			flag=0;
		}
		if(r2 > r) r2 = r;
		if(r1 > r2)
		{
			swap(r1, r2);
			k++;
			flag=0;
		}
		if(k == 2) flag = 1;
	}
	if(flag) ans = r2 - l2; else ans = max(r2 - l1, r1 - l2);
	printf("%d\n", ans<0?0:ans);
	return 0;
}
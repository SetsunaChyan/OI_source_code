#include <cstdio>

/*
单个
O(logn):
p是质数 inv[a]=pow(a,p-2)%p
任意情况下 exgcd

1~p
O(n):
inv[i]=(long long)(p-p/i)*inv[p%i]%p;

阶乘逆元
O(n):
i:n->1
inv[i]=inv[i+1]*(i+1)

*/

int inv[3 * 1000000], n, p;

int main()
{
	scanf("%d%d", &n, &p);
	inv[0] = 0; inv[1] = 1;
	printf("1\n");
	for(int i = 2; i <= n; i++)
	{
		inv[i] = (long long)(p - p / i) * inv[p % i] % p;
		printf("%d\n", inv[i]);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n,cnt;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        if(__gcd(i,n)==1) cnt++;
    printf("%d",cnt);
    return 0;
}

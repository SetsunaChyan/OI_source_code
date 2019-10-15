#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll f[42],sum;

int main()
{
    scanf("%d",&n);
    f[1]=1,f[2]=1;
    for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
    for(int i=1;i<=n;i++) sum+=f[i];
    printf("%lld",sum);
    return 0;
}

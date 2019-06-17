#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=99037660ll;
ll f[1000005],n;

int main()
{
    f[0]=1,f[1]=2,f[2]=4,f[3]=6;
    scanf("%lld",&n);
    for(int i=4;i<=n;i++)
        f[i]=(f[i-4]+f[i-3]+f[i-1])%mod;
    printf("%lld",f[n]);
    return 0;
}
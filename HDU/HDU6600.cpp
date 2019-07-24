#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e6+3;
int n;
ll ans[mod+5];

int main()
{
    ans[1]=1;
    for(int i=2;i<mod;i++)
        ans[i]=ans[i-1]*i%mod;
    while(~scanf("%d",&n))
    {
        if(n>=mod) printf("0\n");
        else printf("%lld\n",ans[n]);
    }
    return 0;
}

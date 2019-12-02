#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,t=0;
int main()
{
    scanf("%lld",&n);
    for(int i=2;i<=n;i++)
    {
        if(i%3!=1)++t;
        ans+=t;
    }
    if(n%3==0)
        printf("%lld.66666666666667",ans-1);
    else
        printf("%lld",ans);
    return 0;
}

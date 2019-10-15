#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=998244353;

int main()
{
    ll a[2];
    a[0]=0,a[1]=1;
    for(int i=2;i<10;i++)
    {
        a[i&1]=(3*a[1^(i&1)]+2*a[i&1])%mod;
        printf("%lld\n",a[i&1]);
        if(a[i&1]==0&&a[1^(i&1)]==1)
        {
            printf("qaq %d\n",i);
            break;
        }
    }
    return 0;
}

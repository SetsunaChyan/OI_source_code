#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d[64];
int n;

void ins(ll x)
{
    for(int i=60;i>=0;i--)
        if(x&(1ll<<i))
            if(!d[i])
            {
                d[i]=x;
                return;
            }
            else x^=d[i];
}

ll mx()
{
    ll ret=0;
    for(int i=60;i>=0;i--)
        if((ret&(1ll<<i))==0) ret^=d[i];
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ll x;
        scanf("%lld",&x);
        ins(x);
    }
    printf("%lld",mx());
    return 0;
}

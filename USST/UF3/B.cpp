#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,d,m,l,now;

int main()
{
    scanf("%lld%lld%lld%lld",&n,&d,&m,&l);
    for(int i=1;i<=n;i++)
    {
        now+=(i*m-m+l-now)/d*d;
        if(now+d<i*m)
        {
            printf("%lld",now+d);
            return 0;
        }
    }
    printf("%lld",(n*m-m+l)/d*d+d);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w,m,k,base=1,g;

int main()
{
    scanf("%lld%lld%lld",&w,&m,&k);
    m--;
    while(base<=m) base*=10,g++;
    ll now=m;
    while(g<18)
    {
        if((base-now-1)*g<=w/k)
        {
            w-=(base-now-1)*g*k;
            now=base-1;
            base*=10,g++;
        }
        else
        {
            now+=(w/(g*k));
            break;
        }
    }
    printf("%lld",now-m);
    return 0;
}

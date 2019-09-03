#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,q;

int main()
{
    scanf("%lld%lld%lld",&n,&m,&q);
    ll k=__gcd(n,m);
    while(q--)
    {
        ll s1,s2,e1,e2,k1,k2;
        scanf("%lld%lld%lld%lld",&s1,&s2,&e1,&e2);
        if(s1==1)
        {
            k1=s2/(n/k);
            if(s2%(n/k)==0) k1--;
        }
        else
        {
            k1=s2/(m/k);
            if(s2%(m/k)==0) k1--;
        }
        if(e1==1)
        {
            k2=e2/(n/k);
            if(e2%(n/k)==0) k2--;
        }
        else
        {
            k2=e2/(m/k);
            if(e2%(m/k)==0) k2--;
        }
        if(k1!=k2)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }

    return 0;
}

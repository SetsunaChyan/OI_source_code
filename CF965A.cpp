#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,s,p;

int main()
{
    scanf("%lld%lld%lld%lld",&k,&n,&s,&p);
    ll t=n/s;
    if(n%s) t++;
    ll q=t*k/p;
    if(t*k%p) q++;
    printf("%lld",q);
    return 0;
}

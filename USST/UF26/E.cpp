#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;

int main()
{
    scanf("%lld%lld",&n,&k);
    ll c2=0,c5=0,t=n;
    while(n%5==0)
        n/=5,c5++;
    while(n%2==0)
        n/=2,c2++;
    ll mul=1;
    while(c2<k) c2++,mul*=2;
    while(c5<k) c5++,mul*=5;
    printf("%lld",mul*t);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long double eps=1e-6;
ll n,k,sum,l,r;

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=0,x;i<n;i++)
        scanf("%lld",&x),sum+=x;
    l=0;r=10000000;
    while(l<r)
    {
        int mid=l+r>>1;
        if(round(((long double)sum+k*mid)/(n+mid))<k-eps) l=mid+1; else r=mid;
    }
    printf("%lld",l);
    return 0;
}

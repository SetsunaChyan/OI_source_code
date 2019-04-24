#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll a[300005],g=0;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%lld",&a[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%lld",&a[i]);
        g=gcd(a[i]-a[i-1],g);
    }
    for(int i=0;i<m;i++)
    {
        ll p;
        scanf("%lld",&p);
        if(g%p==0)
        {
            printf("YES\n%lld %d",a[0],i+1);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
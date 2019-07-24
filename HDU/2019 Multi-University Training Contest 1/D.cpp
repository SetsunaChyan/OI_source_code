#include <bits/stdc++.h>
using namespace std;

int n;
double l[100005],v[100005],s[100005];

bool check(double t)
{
    double last=t*v[n];
    for(int i=n-1;i>=0;i--)
    {
        last=min(last+s[i]-s[i+1]-l[i+1],t*v[i]);
        if(last<=s[i]) return false;
    }
    return true;
}

void solve()
{
    for(int i=0;i<=n;i++) scanf("%lf",&l[i]);
    for(int i=0;i<=n;i++) scanf("%lf",&s[i]);
    for(int i=0;i<=n;i++) scanf("%lf",&v[i]);
    double L=0,R=1e18;
    for(int T=0;T<=100;T++)
    {
        double mid=(L+R)/2;
        if(check(mid)) R=mid; else L=mid;
    }
    printf("%f\n",L);
}

int main()
{
    while(~scanf("%d",&n)) solve();
    return 0;
}

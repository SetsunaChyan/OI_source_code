#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n,a[2000005];

void solve()
{
    scanf("%lld",&n);
    ll t,l=1,r=0,cur=0;
    do
    {
        t=n/l;
        r=t==0?n:(n/t>n?n:n/t);
        a[cur++]=n/l;
        l=r+1;
    }while(l<=n);
    a[cur++]=0;
    sort(a,a+cur);
    printf("%lld\n",cur);
    for(int i=0;i<cur;i++) printf("%lld ",a[i]);
    printf("\n");
}

int main()
{
    int _=1;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

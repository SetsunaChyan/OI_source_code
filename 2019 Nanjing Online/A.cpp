#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

inline +ll getval(ll x,ll y)
{
    if(y<=n/2&&x>=y&&(x+y)<=n)
    {
        ll bt=n+1,l=n-2*(y-1),r=n-1;
        if(y>1) bt+=(l+r)*(r-l+1);
        return bt+n-x-y;
    }
    if(x>=y&&(x+y)>n)
    {
        ll bt=1,l=2*x+1-n,r=n-1;
        if(x!=n) bt+=(l+r)*(n-x)*2;
        return bt+n-y+x-n;
    }
    ll k=getval(n-x+1,n-y+1);
    ll lev=min(x,n-y+1);
    return k+4*(n/2+1-lev);
}

inline ll get(ll x,ll y)
{
    ll tmp=getval(x,y),sum=0;
    while(tmp)
    {
        sum+=tmp%10;
        tmp/=10;
    }
    return sum;
}

void solve()
{
    scanf("%d",&n);
    for(int i=n;i;i--)
    {
        for(int j=1;j<=n;j++)
            printf("%5lld ",get(j,i));
        printf("\n");
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

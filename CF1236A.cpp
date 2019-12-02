#include <bits/stdc++.h>
using namespace std;

int a,b,c;

void solve()
{
    scanf("%d%d%d",&a,&b,&c);
    int ta=a,tb=b,tc=c;
    int ans=0,t=0,ans2=0;
    t=min(a,b/2),ans+=3*t;
    b-=2*t,ans+=3*min(b,c/2);
    t=min(tb,tc/2),ans2+=3*t;
    tb-=t,ans2+=3*min(ta,tb/2);
    printf("%d\n",max(ans,ans2));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

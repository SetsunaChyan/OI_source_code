#include <bits/stdc++.h>
using namespace std;

int b,p,f,h,c;

void solve()
{
    int ans=0;
    scanf("%d%d%d",&b,&p,&f);
    scanf("%d%d",&h,&c);
    if(h>=c)
    {
        int k=b/2;
        ans+=min(k,p)*h;
        b-=2*min(k,p);
        k=b/2;
        ans+=min(k,f)*c;
    }
    else
    {
        int k=b/2;
        ans+=min(k,f)*c;
        b-=2*min(k,f);
        k=b/2;
        ans+=min(k,p)*h;
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

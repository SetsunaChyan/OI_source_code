#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x;
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld",&x);
        ll k=x%6;
        if(k==0||k==2) printf("%lld\n",x/2);
        else if(k==1) printf("%lld\n",4*(x/6)+1);
        else if(k==3||k==5) printf("%lld\n",x/6);
        else printf("%lld\n",x-1);
    }

    return 0;
}

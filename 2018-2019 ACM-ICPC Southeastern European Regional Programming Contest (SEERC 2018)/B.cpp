#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a,b,c,n,x,ans;

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x;
        x=x*x;
        y>>=1;
    }
    return ret;
}

int main()
{
    scanf("%llu%llu%llu%llu",&a,&b,&c,&n);
    ll inv3=fp(3,(1llu<<63)-1);
    if(n%2==0)
    {
        x=n/2-1;
        ans=n*(x*(x+1)/2+2*x);
        if(a==b&&b==c)
            ans*=inv3;
        else if(a==b||b==c)
            ;
        else
            ans*=2;
    }
    else
    {
        x=n/2;
        ans=n*(x*(x+1)/2);
        if(a==b&&b==c)
            ans*=inv3;
        else if(a==b||b==c)
            ;
        else
            ans*=2;
    }
    printf("%llu\n",ans);
    return 0;
}


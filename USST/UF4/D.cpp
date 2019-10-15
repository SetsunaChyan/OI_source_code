#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,ans,as[10],bs[10],t1[10],t2[10],f1,f2;

ll f(ll x)
{
    for(int i=0;i<10;i++)
        t1[i]=x%10,x/=10;
    int i;
    for(i=9;i>=0;i--)
        if(t1[i]) break;
    for(;i>=0;i--)
        t1[i]=9-t1[i];
    ll ret=0;
    for(int i=9;i>=0;i--)
        ret*=10,ret+=t1[i];
    return ret;
}

int main()
{
    scanf("%lld%lld",&a,&b);
    ll x=a+b>>1;
    ans=max(a*f(a),b*f(b));
    for(ll i=5;i<=b;i*=10)
    {
        if(i<a) continue;
        ans=max(ans,i*f(i));
    }
    printf("%lld",ans);
    return 0;
}

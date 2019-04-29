#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,ansk,ans;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main()
{
    scanf("%lld%lld",&a,&b);
    if(a<b) swap(a,b);
    ansk=0;
    ans=lcm(a,b);
    for(ll i=1;i*i<=a-b;i++)
    {
        if((a-b)%i) continue;
        ll x=b/i*i+(b%i!=0)*i-b,t=(a-b)/i;
        ll tmp=lcm(a+x,b+x);
        if(tmp<ans||tmp==ans&&x<ansk)
            ans=tmp,ansk=x;
        x=b/t*t+(b%t!=0)*t-b;
        tmp=lcm(a+x,b+x);
        if(tmp<ans||tmp==ans&&x<ansk)
            ans=tmp,ansk=x;
    }
    printf("%lld",ansk);
    return 0;
}
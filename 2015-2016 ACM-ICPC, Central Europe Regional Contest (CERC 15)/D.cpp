#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
int n,m;
char s[300005];
ll qp(ll a,ll b)
{
    ll ans=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;return ans;
}
int main()
{
    scanf("%d%d%s",&n,&m,s);
    for(int i=0;i<n;i++)s[i]-='0';
    ll cur=0,ans=0;
    for(int i=0;i+1<n;i++)
    {
        cur=(cur*10+s[i])%m;
        if(!cur)
            ++ans;
    }
    bool f=1;
    cur=0;
    for(int i=0;i<n;i++)cur=(cur*10+s[i])%m;
    if(cur)f=0;
    printf("%lld\n",f*qp(2,ans));
    return 0;
}

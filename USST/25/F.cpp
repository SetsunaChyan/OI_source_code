#include <cstdio>

typedef long long ll;
ll n,m,s[35],ans=0;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a,ll b)
{
    if(a==0||b==0) return 0;
    return a/gcd(a,b)*b;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    n--;
    if(n<=0) {printf("0");return 0;}
    for(int i=0;i<m;i++)
        scanf("%lld",&s[i]);
    for(ll i=1;i<(1<<m);i++)
    {
        ll tmp=1,t=i,k=0;
        for(ll j=0;j<m;j++)
        {
            if(t&1) {k++;tmp=lcm(tmp,s[j]);}
            if(tmp>n) break;
            t>>=1;
        }
        if(tmp==0) continue;
        if(tmp>n) continue;
        if(k&1) ans+=n/tmp; else ans-=n/tmp;
    }
    printf("%lld",ans);
    return 0;
}
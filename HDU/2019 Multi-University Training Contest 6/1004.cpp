#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fraction
{
    ll x,y;
};
ll sum,A,B,AS,BS,sumS,k;
int n;

inline Fraction add2Frac(Fraction a,Fraction b)
{
    Fraction ret;
    ret.y=a.y*b.y;
    ret.x=a.x*b.y+a.y*b.x;
    ll k=__gcd(ret.y,ret.x);
    ret.y/=k,ret.x/=k;
    return ret;
}

void solve()
{
    A=B=AS=BS=sum=sumS=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        sumS+=x+y,AS+=x,BS+=y;
        if(x==y)
            sum+=x+y,A+=x,B+=y;
        else if(x<y)
            sum+=2*x,A+=2*x;
        else
            sum+=2*y,B+=2*y;
        if(A==0||B==0)
        {
            k=__gcd(AS*BS,sumS);
            printf("%lld/%lld\n",AS*BS/k,sumS/k);
            continue;
        }
        k=__gcd(A*B,sum);
        printf("%lld/%lld\n",A*B/k,sum/k);
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

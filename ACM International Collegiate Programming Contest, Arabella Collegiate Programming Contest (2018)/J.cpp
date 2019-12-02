#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gao(int i,int j)
{
    if(j<=-1 || j>i)
    {
        return 0;
    }
    if(i==0 && j==0)
    {
        return 1;
    }
    return gao(i-1,j-1)+gao(i-1,j);
}

ll gao2(ll a)
{
    int cnt=0;
    while(a)
    {
        if(a&1)
        {
            cnt++;
        }
        a>>=1;
    }
    ll ans=1ll<<cnt;
    return ans;
}

int main()
{
    int _t;
    scanf("%d",&_t);
    while(_t--)
    {
        ll n;
        scanf("%lld",&n);
        /*
        for(ll m=0;m<=n;m++)
        {
            printf("%lld %lld:%d\n",n,m,gao(n,m));
        }
        */
        printf("%lld\n",n+1-gao2(n));
    }

    return 0;
}

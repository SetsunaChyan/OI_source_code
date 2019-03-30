#include <cstdio>
#include <memory.h>

typedef long long ll;
const ll mod=1e9+7;
ll n,a,b,e[2][2],pa,pb;

void multi(ll x[2][2],ll y[2][2])
{
    ll tmp[2][2];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j]%(mod-1))%(mod-1);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            x[i][j]=tmp[i][j];
}

void fp(ll x[2][2],ll y)
{
    ll ret[2][2];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<2;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x);
        multi(x,x);
        y>>=1;
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            x[i][j]=ret[i][j];
}

ll fp_l(ll x,ll y)
{
    ll ret=1,base=x%mod;
    while(y)
    {
        if(y&1) ret=ret*base%mod;
        base=base*base%mod;
        y>>=1;
    }
    return ret;
}

int main()
{
    while(~scanf("%lld%lld%lld",&a,&b,&n))
    {
        if(n==0) {printf("%lld\n",a);continue;}
        if(n==1) {printf("%lld\n",b);continue;}
        e[0][0]=e[1][0]=e[0][1]=1,e[1][1]=0;
        fp(e,n-2);
        printf("%lld\n",fp_l(b,e[0][0]+e[0][1])*fp_l(a,e[1][0]+e[1][1])%mod);
    }
    return 0;
}
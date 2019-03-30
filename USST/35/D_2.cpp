#include <cstdio>
#include <memory.h>

typedef long long ll;
const ll mod=998244353;
ll e[4][4],x,n;

void multi(ll x[4][4],ll y[4][4])
{
    ll tmp[4][4];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j]%mod)%mod;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            x[i][j]=tmp[i][j];
}

ll fp_ll(ll x,ll y)
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

void fp_matrix(ll base[4][4],ll y)
{
    ll ret[4][4];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<4;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,base);
        multi(base,base);
        y>>=1;
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            base[i][j]=ret[i][j];
}

int main()
{
    scanf("%lld%lld",&n,&x);
    if(x==1)
    {
        printf("%lld",(1+n)*n%mod*fp_ll(2,mod-2)%mod);
        return 0;
    }
    memset(e,0,sizeof(e));
    e[0][0]=e[0][1]=1;
    e[1][1]=e[1][3]=e[2][2]=e[2][3]=e[3][3]=2;
    e[1][2]=4;
    fp_matrix(e,n);
    printf("%lld",(e[0][1]*2%mod+e[0][2]*2%mod+e[0][3]*2%mod)%mod);
    return 0;
}
#include <cstdio>
#include <memory.h>

typedef long long ll;
ll e[2][2],n,mod;

void multi(ll x[2][2],ll y[2][2])
{
    ll tmp[2][2];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j]%mod)%mod;
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

int main()
{
    while(~scanf("%lld%lld",&n,&mod))
    {
        e[0][0]=4,e[0][1]=e[1][1]=1,e[1][0]=0;
        fp(e,(n-1)/2);
        if(n&1) printf("%lld\n",(e[0][0]+e[0][1])%mod); else printf("%lld\n",2*(e[0][0]+e[0][1])%mod);
    }
    return 0;
}
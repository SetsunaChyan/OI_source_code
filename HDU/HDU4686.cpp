#include <cstdio>
#include <memory.h>

typedef long long ll;
const int N=7;
const ll mod=1e9+7;
ll e[N][N],n,a0,b0,ax,ay,bx,by;

ll multi(ll x[N][N],ll y[N][N])
{
    ll tmp[N][N];
    memset(tmp,0,sizeof tmp);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j])%mod;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            x[i][j]=tmp[i][j];
}

void fp(ll x[N][N],ll y)
{
    ll ret[N][N];
    memset(ret,0,sizeof ret);
    for(int i=0;i<N;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x);
        multi(x,x);
        y>>=1;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            x[i][j]=ret[i][j];
}

int main()
{
    while(~scanf("%lld",&n))
    {
        scanf("%lld%lld%lld",&a0,&ax,&ay);
        scanf("%lld%lld%lld",&b0,&bx,&by);
        memset(e,0,sizeof e);
        e[0][0]=e[0][1]=e[1][6]=e[2][4]=e[3][5]=e[4][4]=e[5][5]=e[6][6]=1;
        e[1][1]=ax%mod*bx%mod;
        e[1][2]=ax%mod*by%mod;
        e[1][3]=ay%mod*bx%mod;
        e[2][2]=ax%mod;
        e[3][3]=bx%mod;
        fp(e,n);
        ll ans=e[0][1]*a0%mod*b0+e[0][2]*a0%mod+e[0][3]*b0%mod+e[0][4]*ay%mod+e[0][5]*by%mod+e[0][6]*ay%mod*by%mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
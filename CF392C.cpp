#include <cstdio>
#include <memory.h>

typedef long long ll;
const int N=90;
const ll mod=1e9+7;
ll e[N][N],a[N],n,k,c[N][N],ans=0;

void multi(ll x[N][N],ll y[N][N],int n)
{
    ll tmp[N][N];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j])%mod;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=tmp[i][j];
}

ll fp_ll(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

void fp(ll x[N][N],ll y,int n)
{
    ll ret[N][N];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<n;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x,n);
        multi(x,x,n);
        y>>=1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=ret[i][j];
}

int main()
{
    scanf("%lld%lld",&n,&k);
    memset(a,0,sizeof(a));
    a[0]=1;
    for(int i=1;i<=k+1;i++) a[i]=2*fp_ll(2,k+1-i)%mod;
    for(int i=k+2;i<=2*k+2;i++) a[i]=1;
    c[0][0]=1;
    for(int i=1;i<=k+1;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    e[0][0]=e[0][1]=1;
    for(int i=1;i<=k+1;i++)
    {
        ll tmp=1;
        for(int j=i;j<=k+1;j++)
            e[i][j]=c[k-i+1][k-j+1];
        for(int j=k+i+1;j<=2*k+2;j++)
        {
            e[i][j]=tmp*c[k-i+1][2*k-j+2]%mod;
            tmp<<=1;
            tmp%=mod;
        }
    }
    for(int i=k+2;i<=2*k+2;i++)
        e[i][i-k-1]=1;
    fp(e,n-1,2*k+3);
    for(int i=0;i<=2*k+2;i++) ans=(ans+e[0][i]*a[i])%mod;
    printf("%lld",ans);

    return 0;
}
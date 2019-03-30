#include <cstdio>
#include <memory.h>

typedef long long ll;
const int N=12;
const ll mod=1e7+7;
ll a[N][N],e[N][N],n,m;

void multi(ll x[N][N],ll y[N][N],int n)
{
    ll tmp[N][N];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j]%mod)%mod;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=tmp[i][j];
}

void fp(ll x[N][N],ll y,int n)
{
    ll base[N][N];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            base[i][j]=x[i][j];
    while(y)
    {
        if(y&1) multi(x,base,n);
        multi(base,base,n);
        y>>=1;
    }
}

int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        memset(e,0,sizeof(e));
        a[0][0]=23;
        for(int i=1;i<=n;i++)
            a[0][i]=(10*a[0][i-1]+3)%mod;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i][0]);
            a[i][0]%=mod;   
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=(a[i-1][j]+a[i][j-1])%mod;
        for(int i=1;i<=n;i++)
            e[i][i]=e[i][i-1]=1;
        e[0][0]=10,e[0][n+1]=e[n+1][n+1]=1;
        fp(e,m-1,n+2);
        ll ans=0;
        for(int i=0;i<=n;i++)
            ans=(ans+e[n][i]*a[i][n-i]%mod)%mod;
        ans=(ans+3*e[n][n+1]%mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
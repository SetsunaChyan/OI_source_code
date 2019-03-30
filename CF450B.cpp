#include <cstdio>
#include <memory.h>

typedef long long ll;
const ll mod=1e9+7;
ll ans[2][2],m[2][2],a[2],n;

void multi(ll x[2][2],ll y[2][2])
{
    int temp[2][2];
    memset(temp,0,sizeof(temp));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                temp[i][j]=(temp[i][j]+x[i][k]*y[k][j]%mod)%mod;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            x[i][j]=temp[i][j];
}

void fp(ll ans[2][2],ll x[2][2],ll y)
{
    ll base[2][2];
    memset(ans,0,sizeof ans);
    for(int i=0;i<2;i++)
        ans[i][i]=1;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            base[i][j]=x[i][j];
    while(y)
    {
        if(y&1) multi(ans,base);
        multi(base,base);
        y>>=1;
    }
}

int main()
{
    scanf("%lld%lld%lld",&a[1],&a[0],&n);
    a[1]=(a[1]+mod)%mod;a[0]=(a[0]+mod)%mod;
    m[0][0]=1;m[0][1]=-1;m[1][0]=1;m[1][1]=0;
    if(n<=2)
    {
        printf("%lld",(a[2-n]+mod)%mod);
        return 0;
    }
    fp(ans,m,n-2);
    ll ret=(a[0]*ans[0][0]%mod+a[1]*ans[0][1]%mod)%mod;
    ret=(ret+mod)%mod;
    printf("%lld",ret);
    return 0;
}
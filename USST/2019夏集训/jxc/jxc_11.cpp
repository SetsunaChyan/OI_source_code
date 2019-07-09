#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll q,n,x,y,a,b,c[100005],d[100005],f[100005];

int main()
{
    memset(d,0,sizeof(d));
    scanf("%lld%lld%lld%lld%lld",&n,&x,&y,&a,&b);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    f[0]=0,f[1]=x,f[2]=y;
    for(int i=3;i<=n+4;i++) f[i]=(a*f[i-2]+b*f[i-1])%mod;
    scanf("%lld",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        d[l]=(d[l]+x)%mod,d[l+1]=(d[l+1]+y-b*x+mod)%mod;
        d[r+1]=(d[r+1]+mod-f[r-l+2])%mod,d[r+2]=(d[r+2]+mod*mod-a*f[r-l+1])%mod;
    }
    printf("%lld ",(c[1]+d[1])%mod);
    for(int i=2;i<=n;i++)
    {
        d[i]=(d[i]+a*d[i-2]+b*d[i-1])%mod;
        printf("%lld ",(c[i]+d[i])%mod);
    }
    return 0;
}

/*
5 2 3 4 5
0 0 0 0 0
6
1 1
2 4
3 5
1 5
1 5
1 5
*/

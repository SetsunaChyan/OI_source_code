#include <cstdio>

typedef unsigned long long ll;
ll f[3000000];

inline ll fp(ll a,ll b,int c)
{
    ll base=a,ret=1;
    while(b)
    {
        if(b&1) ret=(ret*base)%c;
        base=(base*base)%c;
        b>>=1;
    }
    return ret;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        ll a,b;
        int n,k,i;
        scanf("%llu%llu%d",&a,&b,&n);
        f[0]=0;f[1]=1%n;
        for(i=2;;i++)
        {
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i]==f[1]&&f[i-1]==0) break;
        }
        k=i-1;
        printf("%llu\n",f[fp(a%k,b,k)]);
    }
    return 0;
}
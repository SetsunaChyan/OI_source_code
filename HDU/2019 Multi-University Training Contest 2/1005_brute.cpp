#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,T,a[100],tmp[100];

int fp(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

int inv(int x[100],int n)
{
    int ret=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(x[j]<x[i]) ret++;
    return ret;
}

signed main()
{
    for(int i=1;i<=10000;i++)
        if(8*fp(i,mod-2)%mod==554580197)
            printf("%lld\n",i);
    printf("QAQ\n");
    //printf("%lld/%lld=%lld\n",9ll,8ll,1*fp(11,mod-2)%mod);
    scanf("%lld",&T);
    int fm=0;int ans=0;
    for(int i=1;i<=T;i++)
    {
        int jc=1;
        for(int j=1;j<=i;j++) jc*=j,jc%=mod;
        fm+=jc*fp(2,i)%mod,fm%=mod;
    }
    for(int n=T;n<=T;n++)
    {
        for(int i=1;i<=n;i++) a[i]=i;
        do
        {
            for(int i=0;i<(1<<n);i++)
            {
                int tot=1,t=i,k;
                for(int j=0;j<n;j++)
                {
                    if(t&1) tmp[tot++]=a[j+1];
                    t>>=1;
                }
                ans+=inv(tmp,tot);
            }
        }while(next_permutation(a+1,a+n+1));
    }
    printf("%lld/%lld=%lld\n",ans,fm,ans*fp(fm,mod-2));
    return 0;
}

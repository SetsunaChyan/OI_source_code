#include <cstdio>

typedef long long ll;
ll n,p,tot=0,pr[40],t[40],ans=1;

int main()
{
    scanf("%lld%lld",&n,&p);
    for(ll i=2;i*i<=p;i++)
    {
        if(p%i==0)
        {
            t[tot]=0;
            pr[tot]=i;
            while(p%i==0)
            {
                t[tot]++;
                p/=i;
            }
            tot++;
        }
    }
    if(p!=1) {t[tot]=1;pr[tot++]=p;}
    for(int i=0;i<tot;i++)
        for(int j=0;j<t[i]/n;j++)
            ans*=pr[i];
    printf("%lld",ans);
    return 0;
}
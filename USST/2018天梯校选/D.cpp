#include <cstdio>
#include <memory.h>

typedef long long ll;
const int MAXN=1e6+5;
int n,q,rt=0,ct=0,rvis[MAXN],cvis[MAXN];
ll rsum=0,csum=0;

int main()
{
    memset(rvis,1,sizeof(rvis));
    memset(cvis,1,sizeof(cvis));
    scanf("%d%d",&n,&q);
    while(q--)
    {
        char opt;
        ll k;
        scanf(" %c%lld",&opt,&k);
        if(opt=='C')
        {
            if(cvis[k])
            {
                printf("%lld\n",(1ll+n)*n/2+k*(n-rt)-rsum);
                ct++;
                csum+=k;
                cvis[k]=0;
            }
            else
                printf("0\n");
        }
        else
        {
            if(rvis[k])
            {
                printf("%lld\n",(1ll+n)*n/2+k*(n-ct)-csum);
                rt++;
                rsum+=k;
                rvis[k]=0;
            }
            else
                printf("0\n");
        }
    }
    return 0;
}
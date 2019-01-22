#include <cstdio>

typedef unsigned long long ll;
ll p10[30],k,m,l,r;
int ln,lk;

int len(ll x)
{
    int i=0;
    while(x>=p10[i]&&i<=19) i++;
    return i;
}

ll check(ll n)
{
    ln=len(n);
    ll ret=0;
    for(int i=1;i<lk;i++)
    {
        ll tmp=k;
        while(tmp>=p10[i]) tmp/=10;
        ret+=tmp-p10[i-1]+1;
    }
    for(int i=lk;i<ln;i++)
        ret+=k*p10[i-lk]-p10[i-1];
    if(n<k*p10[ln-lk])
        ret+=n-p10[ln-1]+1;
    else    
        ret+=k*p10[ln-lk]-p10[ln-1];
    return ret+1;
}

int main()
{
    p10[0]=1;
    for(int i=1;i<20;i++)
        p10[i]=p10[i-1]*10;
    p10[19]=-1;

    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%llu%llu",&k,&m);
        lk=len(k);
        l=k,r=-1,r>>=1;
        while(l<r)
        {
            ll mid=(l+r)>>1;
            if(check(mid)<m) l=mid+1; else r=mid;
        }
        if(check(l)==m)
            printf("%llu\n",l);
        else
            printf("0\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll k,x;

ll cal(ll n)
{
    ll current,high,low,ret=0,i=1;
    while(n/i!=0)
    {
        current=n/i%10;
        high=n/(i*10);
        low=n-n/i*i;
        if(current<k) ret+=high*i;
        if(k==current) ret+=high*i+low+1;
        if(current>k) ret+=(high+1)*i;
        i*=10;
    }
    if(k==0&&n<10) return 1;
    if(k==0&&n>=10) ret-=i/10;
    return ret;
}

ll solve(ll l,ll r)
{
    ll m1,m2,t1,t2;
    while(l<r)
    {
        m1=(2*l+r)/3;
        m2=(2*r+l+2)/3;
        if(cal(m1)>=m1) t1=1; else t1=-1;
        if(cal(m2)>m2) t2=1; else t2=-1;
        if(t1*t2==-1)
            r=m2-1,l=m1+1;
        else
            l=m1+1;
    }
    return l;
}

void solve()
{
    scanf("%llu%llu",&k,&x);
    ll l=0,r=x,ans=0;
    while(l<r)
    {
        ll tmp=solve(l,r);
        printf("qaq %llu\n",tmp);
        if(cal(tmp)==tmp) l=tmp,ans=tmp;
        else if(cal(tmp-1)==tmp-1&&tmp-1>ans) l=tmp-1,ans=tmp-1;
        else break;
    }
    printf("%llu\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

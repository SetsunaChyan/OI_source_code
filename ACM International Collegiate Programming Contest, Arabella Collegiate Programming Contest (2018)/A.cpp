#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,p[19];
bool f=0;
int main()
{
    p[0]=1;
    for(int i=1;i<=11;i++)
        p[i]=p[i-1]*10;
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld",&a,&b);a*=b;
        ll t=a,len=0;
        while(t)
            ++len,t/=10;
        printf("%lld %lld\n",a,len);
        if(a<0)a=-a,f=1;
        for(ll x=1;x<=9;x++)
            for(ll y=x;y<=9;y++)
                for(ll u=1;u<=9;u++)
                    for(ll v=u;v<=9;v++)
                        for(ll l=max(len-2,0LL);l<=min(18LL,len+1);l++)
                            for(ll r=max(len-2,0LL);r<=min(18LL,len+1);r++)
                                if(x*y*p[l]+u*v*p[r]==a)
        {
            if(!f)
                printf("%lld x %lld + %lld x %lld\n",x*p[l/2],y*p[(l+1)/2],u*p[r/2],v*p[(r+1)/2]);
            else
                printf("-%lld x %lld - %lld x %lld\n",x*p[l/2],y*p[(l+1)/2],u*p[r/2],v*p[(r+1)/2]);
            goto ok;
        }
        else if(x*y*p[l]-u*v*p[r]==a)
        {
            if(!f)
                printf("%lld x %lld - %lld x %lld\n",x*p[l/2],y*p[(l+1)/2],u*p[r/2],v*p[(r+1)/2]);
            else
                printf("-%lld x %lld + %lld x %lld\n",x*p[l/2],y*p[(l+1)/2],u*p[r/2],v*p[(r+1)/2]);
            goto ok;
        }
        ok:;
    }
    return 0;
}

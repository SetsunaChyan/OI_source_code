#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ans,a[100005],col[100005],b,w;
char c;

void solve()
{
    b=w=ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%*c%c",&a[i],&c);
        if(c=='B') col[i]=1,b+=a[i]; else col[i]=0,w+=a[i];
    }
    if(w==0||b==0)
    {
        printf("%lld\n",w+b);
        return;
    }
    ll t=__gcd(w,b);w/=t,b/=t;
    ll cb=(col[0]==1)*a[0],cw=(col[0]==0)*a[0],flg;
    for(int i=1;i<n;i++)
    {
        flg=0;
        if(cw%w!=0&&col[i]==1) flg=1;
        if(cb%b!=0&&col[i]==0) flg=1;
        if(flg)
        {
            cb+=(col[i]==1)*a[i];
            cw+=(col[i]==0)*a[i];
            continue;
        }
        if(col[i])
        {
            ll k=cw/w;
            k=k*b-cb;
            if(k>=1&&k<=a[i])
            {
                cw=0;
                cb=a[i]-k;
                ans++;
            }
            else cb+=a[i];
        }
        else
        {
            ll k=cb/b;
            k=k*w-cw;
            if(k>=1&&k<=a[i])
            {
                cb=0;
                cw=a[i]-k;
                ans++;
            }
            else cw+=a[i];
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

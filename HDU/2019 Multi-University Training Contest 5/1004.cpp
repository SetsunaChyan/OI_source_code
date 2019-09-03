#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,c;
struct node
{
    ll a,b;
    bool operator <(const node &y)const
    {
        return b*y.a>y.b*a;
    }
}e[100005];
ll l[100005],r[100005],s[100005];
struct f
{
    ll fz,fm;
    bool operator <(const f &b)const
    {
        return fz*b.fm<b.fz*fm;
    }
};
set<f>ans;
int main()
{
    int _;scanf("%lld",&_);
    while(_--)
    {
        ans.clear();
        scanf("%lld%lld",&n,&c);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&e[i].a,&e[i].b);
        sort(e+1,e+n+1);
        r[n+1]=0;
        for(int i=n;i>=1;i--)
            r[i]=r[i+1]+e[i].a;
        l[0]=0;
        for(int i=1;i<=n;i++)
            l[i]=l[i-1]+e[i].a;
        s[0]=0;
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+e[i].b;
        e[0].b=1e9;
        e[0].a=1;
        e[n+1].b=-1e9;
        e[n+1].a=1;
        for(int i=1;i<=n+1;i++)
        {
            if(e[i].b*e[i-1].a==e[i-1].b*e[i].a)
                continue;
            ll allb=s[i-1]-(s[n]-s[i-1]);
            if(l[i-1]-r[i]==0&&r[i]==c)
            {
                printf("-1\n");
                goto ok;
            }
            if(l[i-1]-r[i]==0) continue;
            ll fz,fm;
            fz=c-allb;
            fm=l[i-1]-r[i];
            //printf("%d/%d\n",fz,fm);
            ll gcd=__gcd(fz,fm);
            fz/=gcd,fm/=gcd;
            if(fm<0)
                fz=-fz,fm=-fm;
            //printf("%d/%d\n",fz,fm);
            if(fz*e[i-1].a>=-e[i-1].b*fm&&fz*e[i].a<=-e[i].b*fm)
                ans.insert({fz,fm});
        }
        printf("%d",ans.size());
        for(auto v:ans)
            printf(" %lld/%lld",v.fz,v.fm);
        puts("");
        ok:;
    }
    return 0;
}

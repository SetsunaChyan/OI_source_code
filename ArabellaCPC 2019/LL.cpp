#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7,inv=5e8+4;
ll n,m,r,c,ans,a[111][111];
ll f(int x,int y)
{
    return x*m+y+1;
}
ll gao(int x,int y)
{
    printf("start %d %d\n",x+1,y+1);
    ll t=0;
    set<int>s;
    while(!s.count(f(x,y)))
        a[x][y]=1,t+=f(x,y),printf("%d %d %lld\n",x+1,y+1,f(x,y)),s.insert(f(x,y)),x=(x+r)%n,y=(y+c)%m;
    printf("end=%lld\n",t);
    return t;
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&r,&c);
    ll g1=__gcd(n,r),g2=__gcd(m,c);
    ll t1=n/g1,t2=m/g2;
    printf("%lld %lld %lld %lld\n",g1,g2,t1,t2);
    //for(int i=0;i<n;i++)
    //    for(int j=0;j<m;j++)
    //        ans=max(ans,gao(i,j));
    printf("%lld\n",ans=gao(g1-1,g2-1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            printf("%lld%c",a[i][j]," \n"[j+1==m]);
    return 0;
}

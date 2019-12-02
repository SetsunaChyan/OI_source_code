#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll x,k,ans;
vector<ll> a;

int main()
{
    scanf("%d%lld%lld",&n,&x,&k);
    if(k==0&&x==1) return printf("0"),0;
    for(int i=0;i<n;i++)
    {
        ll tmp;
        scanf("%lld",&tmp);
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    auto now=a.begin();
    for(auto p:a)
    {
        auto l=lower_bound(a.begin(),a.end(),max((k+(p-1)/x)*x,p));
        auto r=upper_bound(a.begin(),a.end(),(k+(p-1)/x)*x+x-1);
        //printf("? %lld %lld\n",(k+p/x)*x,(k+p/x)*x+x-1);
        if(l==a.end()) continue;
        ll lc=l-a.begin(),rc;
        if(r==a.end()) rc=n; else rc=r-a.begin();
        //printf("! %lld %lld\n",*l,*r);
        ans+=rc-lc;
        now++;
    }
    printf("%lld",ans);
    return 0;
}

/*
8 1 1
1 1 2 2 3 3 4  4

*/

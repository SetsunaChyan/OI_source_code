#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,pro[30],cnt[30];
vector<int> a;

void solve()
{
    a.clear();
    memset(cnt,0,sizeof(cnt));
    scanf("%lld",&x);
    int cur=2;
    while(x)
    {
        a.push_back(x%cur);
        x/=cur;
        cur++;
    }
    sort(a.begin(),a.end(),greater<int>());
    ll ans=1,tmp=1;cur=1;
    for(auto p:a)
    {
        ll k=a.size()-p-cur+2;
        if(!p) k--;
        ans*=k;
        cnt[p]++;
        cur++;
    }
    for(int i=0;i<a.size();i++) ans/=pro[cnt[i]];
    if(a.back()==0)
    {
        a.pop_back();
        cur=1;
        memset(cnt,0,sizeof(cnt));
        for(auto p:a)
        {
            ll k=a.size()-p-cur+2;
            if(!p) k--;
            tmp*=k;
            cnt[p]++;
            cur++;
        }
        for(int i=0;i<a.size();i++) tmp/=pro[cnt[i]];
        ans-=tmp;
    }
    printf("%lld\n",ans-1);
}

int main()
{
    pro[0]=1;
    for(int i=1;i<=25;i++) pro[i]=pro[i-1]*i;
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

/*

*/

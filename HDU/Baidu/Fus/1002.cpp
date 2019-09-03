#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
ll a,b,c,d,cur,cnt;
char ans[100000];

void inc(ll &x)
{
    x+=1;
}

void solve()
{
    cnt=0;
    cur=0;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(b==d&&a==c)
    {
        printf("Yes");
        puts("");
        puts("");
        return;
    }
    if(a==b)
    {
        printf("No");
        puts("");
        return;
    }
    ll n=(c-b)/(a-b);
    ll m=(d-a)/(b-a);
    while(n>1||m>1)
    {
        if(n>=m) n-=(n+m)/2,ans[cur++]='B';
        else m-=(n+m)/2,ans[cur++]='A';
        inc(cnt);
        if(cnt>200) break;
    }
    reverse(ans,ans+cur);
    pll t={a,b};
    for(int i=0;i<cur;i++)
        if(ans[i]=='A') t=make_pair(t.first,2*t.second-t.first);
        else t=make_pair(2*t.first-t.second,t.second);
    ans[cur]=0;
    if(t.first==c&&t.second==d)
        printf("Yes\n%s\n",ans);
    else
        printf("No\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

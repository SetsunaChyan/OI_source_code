#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s,t;
const ll mod=1e9+7;

void solve()
{
    ll cnt=1,n;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i]&&s[i]=='1') cnt=0;
        else if(s[i]==t[i]&&s[i]=='1') cnt*=2,cnt%=mod;
    }
    if(cnt==0) cout<<"IMPOSSIBLE\n"; else cout<<cnt<<"\n";
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

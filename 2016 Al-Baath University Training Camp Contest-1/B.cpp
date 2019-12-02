#include <bits/stdc++.h>
using namespace std;

string s,t;

void solve()
{
    cin>>s>>t;
    for(auto &c:s)
    {
        if(c>='A'&&c<='Z') c=c-'A'+'a';
        if(c=='p') c='b';
        if(c=='i') c='e';
    }
    for(auto &c:t)
    {
        if(c>='A'&&c<='Z') c=c-'A'+'a';
        if(c=='p') c='b';
        if(c=='i') c='e';
    }
    if(s==t) cout<<"Yes\n"; else cout<<"No\n";
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

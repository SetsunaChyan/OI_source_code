#include <bits/stdc++.h>
using namespace std;

int ans,num,n;
map<int,int> mp;

void solve()
{
    mp.clear();
    ans=0;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%*s%d",&x);
        mp[x]++;
        if(mp[x]==ans) num=min(num,x);
        else if(mp[x]>ans) ans=mp[x],num=x;
    }
    printf("%d\n",num);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

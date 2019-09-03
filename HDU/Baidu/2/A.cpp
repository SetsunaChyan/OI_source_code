#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int v,sum=0,t;
    vector<int> ans;
    scanf("%d",&v);
    t=v;
    while(t) sum+=t%10,t/=10;
    for(int i=1;i<=sum;i++)
        if(sum%i==0&&v%i==0) ans.push_back(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int vis[1000005],n;
set<int> s;
vector<int> ans;

void seive()
{
    for(ll i=2;i<=1000000;i++)
        if(!vis[i])
        {
            s.insert(i);
            for(ll j=i*i;j<=1000000;j+=i) vis[j]=1;
        }
}

int main()
{
    seive();
    scanf("%d",&n);
    for(auto p:s)
        if(p<=n&&s.find(p-2)!=s.end()) ans.push_back(p-2);
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",2,p);
    return 0;
}

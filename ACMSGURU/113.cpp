#include <bits/stdc++.h>
using namespace std;

int vis[36000];
set<int> prime;

void seive()
{
    int n=35000;
    for(int i=2;i<n;i++)
        if(!vis[i])
        {
            prime.insert(i);
            for(int j=i*i;j<=n;j+=i) vis[j]=1;
        }
}

bool isp(int x)
{
    if(x<=1) return false;
    for(int i=2;i*i<=x;i++) if(x%i==0) return false;
    return true;
}

void solve()
{
    int n;
    scanf("%d",&n);
    for(auto p:prime)
        if(n%p==0&&isp(n/p))
        {
            printf("Yes\n");
            return;
        }
    printf("No\n");
}

int main()
{
    seive();
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

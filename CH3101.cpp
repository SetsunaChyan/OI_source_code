#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,vis[1000005],num[1000005];
vector<int> prime;

void sel()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=1000000;i++)
        if(!vis[i])
        {
            prime.push_back(i);
            for(int j=i<<1;j<=1000000;j+=i) vis[j]=1;
        }
}

int main()
{
    sel();
    scanf("%d",&n);
    for(int i=0;i<prime.size();i++)
    {
        ll p=prime[i];
        if(p>n) break;
        for(ll j=p;j<=n;j*=p)
            num[i]+=n/j;
    }
    for(int i=0;i<prime.size();i++)
        if(num[i])
            printf("%d %d\n",prime[i],num[i]);
    return 0;
}

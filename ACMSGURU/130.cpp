#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k;
map<int,ll> mp;

ll f(int x)
{
    if(x==0) return 1;
    if(mp[x]) return mp[x];
    ll ret=0;
    for(int i=0;i<x;i++)
        ret+=f(i)*f(x-i-1);
    return mp[x]=ret;
}

int main()
{
    scanf("%d",&k);
    printf("%lld %d",f(k),k+1);
    return 0;
}

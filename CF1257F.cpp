#include <bits/stdc++.h>
using namespace std;

int n,a[105];
map<vector<int>,int> mp;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int mask=0;mask<(1<<15);mask++)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
            v.push_back(__builtin_popcount((a[i]>>15)^mask));
        for(int i=1;i<n;i++) v[i-1]=v[i]-v[i-1];
        v.pop_back();
        mp[v]=mask;
    }
    for(int mask=0;mask<(1<<15);mask++)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
            v.push_back(__builtin_popcount((a[i]&((1<<15)-1))^mask));
        for(int i=1;i<n;i++) v[i-1]-=v[i];
        v.pop_back();
        if(mp.count(v)) return printf("%d",(mp[v]<<15)+mask),0;
    }
    printf("-1");
    return 0;
}
